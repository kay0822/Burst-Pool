#ifndef WEBSOCKET_HPP_
#define WEBSOCKET_HPP_

#include <stdint.h>

#define WS_CONT		0x0
#define WS_TEXT		0x1
#define WS_BIN		0x2
#define WS_RSV3		0x3
#define WS_RSV4		0x4
#define WS_RSV5		0x5
#define WS_RSV6		0x6
#define WS_RSV7		0x7
#define WS_CLOSE	0x8
#define WS_PING		0x9
#define WS_PONG		0xA
#define WS_CRSVB	0xB
#define WS_CRSVC	0xC
#define WS_CRSVD	0xD
#define WS_CRSVE	0xE
#define WS_CRSVF	0xF


class WebSocket {
	public:
		bool fin;
		bool rsv1;
		bool rsv2;
		bool rsv3;
		uint8_t opcode;
		bool mask;
		uint64_t payload_len;
		uint32_t masking_key;
		uint8_t *payload_data;
		uint16_t close_code;

		WebSocket();
		uint64_t unpack(uint8_t *buffer, uint64_t buffer_len);
		bool pack(uint8_t *buffer, uint64_t *buffer_len, uint64_t *payload_offset);
		void replace_payload(const uint8_t *buffer, uint64_t buffer_len);
		~WebSocket();
};

#endif
