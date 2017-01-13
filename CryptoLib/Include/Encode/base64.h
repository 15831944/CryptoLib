/*************************************************************************
�ı���ulwanski��MD5�⣺https://github.com/ulwanski/md5
*************************************************************************/
#pragma once

namespace CryptoLib {
class Encode_Base64 {
public:
	static STRX Encode(STRX dat);
	static STRX Decode(STRX dat);

protected:
	static const std::string base64_chars;
	static inline bool is_base64(unsigned char c);
};
}