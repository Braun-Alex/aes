#include "AES.h"

using namespace Poco;

std::string AES::encrypt(const std::string& data, const std::string& passphrase) {
    try {
        const std::string initializationVector = generateSalt();
        const Crypto::CipherKey key(AES_MODE, passphrase, initializationVector);
        Crypto::Cipher::Ptr cipher = Crypto::CipherFactory::defaultFactory().createCipher(key);
        return encode(initializationVector + cipher->encryptString(data));
    } catch (const Exception& exception) {
        Util::Application::instance().logger().error(exception.displayText());
        return "";
    }
}

std::string AES::decrypt(const std::string& data, const std::string& passphrase) {
    try {
        const std::string decodedData = decode(data);
        const auto delimiter = decodedData.begin() + INITIALIZATION_VECTOR_LENGTH;
        const std::string initializationVector(decodedData.begin(), delimiter);
        const Crypto::CipherKey key(AES_MODE, passphrase, initializationVector);
        Crypto::Cipher::Ptr cipher = Crypto::CipherFactory::defaultFactory().createCipher(key);
        const std::string encryptedData(delimiter, decodedData.end());
        return cipher->decryptString(encryptedData);
    } catch (const Exception& exception) {
        Util::Application::instance().logger().error(exception.displayText());
        return "";
    }
}

std::string AES::encode(const std::string& data) {
    std::stringstream encodedStream;
    Base64Encoder encoder(encodedStream);
    encoder.write(reinterpret_cast<const char*>(data.data()), static_cast<int>(data.size()));
    encoder.close();
    return encodedStream.str();
}

std::string AES::decode(const std::string& data) {
    std::stringstream encodedStream(data);
    Base64Decoder decoder(encodedStream);
    std::vector<unsigned char> decodedData;

    int character = decoder.get();
    while (character != -1) {
        decodedData.push_back(static_cast<unsigned char>(character));
        character = decoder.get();
    }

    return {decodedData.begin(), decodedData.end()};
}

std::string AES::generateSalt() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 255);
    std::string salt;
    salt.reserve(INITIALIZATION_VECTOR_LENGTH);
    for (size_t i = 0; i < INITIALIZATION_VECTOR_LENGTH; ++i) {
        salt += CHARSET[dist(gen) % CHARSET.size()];
    }
    return salt;
}