#pragma once

#include "Poco/Util/Application.h"
#include "Poco/Crypto/Cipher.h"
#include "Poco/Crypto/CipherKey.h"
#include "Poco/Crypto/CipherFactory.h"
#include "Poco/Base64Encoder.h"
#include "Poco/Base64Decoder.h"

#include <vector>
#include <sstream>
#include <string>
#include <random>

const int INITIALIZATION_VECTOR_LENGTH = 16;
const std::string AES_MODE = "aes-256-cbc";
const std::string CHARSET = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

class AES {
public:
    static std::string encrypt(const std::string& data, const std::string& passphrase);
    static std::string decrypt(const std::string& data, const std::string& passphrase);

private:
    static std::string encode(const std::string& data);
    static std::string decode(const std::string& data);
    static std::string generateSalt();
};