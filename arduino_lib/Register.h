#ifndef REGISTER_H
#define REGISTER_H


#include <stdint.h>
#include "constexpr_util.h"


namespace periph { namespace periph_detail {


template<typename Register_, uint8_t StartBit_, uint8_t Length_>
class RegisterValue {
private:
	static volatile uint16_t* get_addr_ptr() {
		return reinterpret_cast<volatile uint16_t*>(Register_::address);
	}
public:
	template<uint16_t Value>
	static void write() {
		static_assert(has_no_more_bits<Value, Length_>::value,
								"More bits written to register value then it is long");

		write(Value);
	}

	static void write(uint16_t value) {
		constexpr static uint16_t mask = ~((constexpr_pow<2, Length_>::value - 1) << StartBit_);

		uint16_t data = *get_addr_ptr();
		data = data & mask;
		data = data | (value << StartBit_);


		*get_addr_ptr() = data;
	}

	template<typename T>
	static T read_as() {
		constexpr uint32_t mask = (~0u >> (16u - StartBit_ - Length_)) - ~(~0u << StartBit_);

		uint16_t data = *get_addr_ptr();
		data = (data & mask) >> StartBit_;

		return static_cast<T>(data);
	}

	uint16_t read() {
		uint16_t data = *get_addr_ptr();

		return data;
	};
};


}} // namespace periph::periph_detail


#endif
