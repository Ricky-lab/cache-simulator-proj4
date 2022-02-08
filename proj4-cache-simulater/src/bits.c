#include "bits.h"
#include "cache.h"

int get_set(Cache *cache, address_type address) {
  // TODO:
  //  Extract the set bits from a 32-bit address.
  //
 // printf("the address is %d\n", address);
  int i = 32 - cache->block_bits - cache->set_bits;
  //printf("left shift %d bits", i);

  address = address << ( 32 -  cache->block_bits - cache->set_bits);
  //printf("now the address is %d\n", address);

  //printf("now right shift %d bits\n", 32 - cache->set_bits);
  address = address >> ( 32 - cache->set_bits );

  //printf("finally the address is %d\n", address);
  return address;
}

int get_line(Cache *cache, address_type address) {
  // TODO:
  // Extract the tag bits from a 32-bit address.
  //
  return address >> (cache->set_bits + cache->block_bits);
}

int get_byte(Cache *cache, address_type address) {
  // TODO
  // Extract the block offset (byte index) bits from a 32-bit address.
  //
  return (address << ( 32 - cache->block_bits))>>(32 - cache->block_bits) ;
}
