#include <iostream>
#include <iomanip>
#include <sstream>
#include <openssl/sha.h>
#include <string>
#include <random>

// Generate a random salt
std::string generateSalt(size_t length = 16) {
    const char charset[] = "0123456789"
                           "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                           "abcdefghijklmnopqrstuvwxyz";
    std::default_random_engine rng(std::random_device{}());
    std::uniform_int_distribution<> dist(0, sizeof(charset) - 2);
    
    std::string salt;
    for (size_t i = 0; i < length; ++i) {
        salt += charset[dist(rng)];
    }
    return salt;
}

// Convert bytes to hex string
std::string toHexString(const unsigned char* hash, size_t length) {
    std::stringstream ss;
    for (size_t i = 0; i < length; ++i)
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    return ss.str();
}

// Hash a password with salt using SHA-256
std::string hashPasswordWithSalt(const std::string& password, const std::string& salt) {
    std::string salted = salt + password;
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256(reinterpret_cast<const unsigned char*>(salted.c_str()), salted.size(), hash);
    return toHexString(hash, SHA256_DIGEST_LENGTH);
}
/*
int main() {
    std::string password = "mySecurePassword";
    std::string salt = generateSalt();
    std::string hashed = hashPasswordWithSalt(password, salt);

    std::cout << "Salt: " << salt << "\n";
    std::cout << "Hashed: " << hashed << "\n";
    return 0;
}*/