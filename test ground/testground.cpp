#include "Testground.h"
#include <cstdlib>
#include <cstring>

Testground::Testground()
{
  position = {2,2};
  map = {
  {"R","R","R","R","R","R","R","R","R","R","R","R","R","R","R","R","R","R","R","R","R","R","R","R","R","R","R","R","R","R"},
  {"R","G","G","G","R","R","R","R","R","G","G","G","G","R","R","R","G","G","G","G","G","G","G","G","G","G","G","G","G","R"},
  {"R","G","G","G","G","G","G","G","G","G","G","G","G","G","G","G","G","G","G","G","G","G","G","G","G","G","G","G","G","R"},
  {"R","G","G","G","G","G","G","G","G","G","G","G","G","G","G","G","G","G","G","G","G","G","G","G","G","G","G","O","G","R"},
  {"R","G","O","O","G","G","G","G","G","G","G","G","G","G","G","G","G","G","G","G","G","O","O","G","G","G","G","O","G","R"},
  {"R","G","O","O","G","G","G","G","O","O","O","G","G","O","O","O","O","O","O","O","O","O","O","G","G","G","G","G","G","R"},
  {"R","G","G","G","G","G","G","G","O","O","O","G","G","O","O","O","O","O","O","O","O","O","O","G","G","G","O","G","G","R"},
  {"R","G","G","G","G","G","G","G","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","G","G","R"},
  {"R","G","G","G","G","G","G","G","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","G","G","R"},
  {"R","G","G","G","G","G","G","G","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","G","G","G","R"},
  {"R","G","G","G","G","G","G","G","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","G","G","G","R"},
  {"R","G","G","G","G","G","G","G","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","G","G","G","G","R"},
  {"R","G","G","G","G","G","G","G","G","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","G","G","G","G","R"},
  {"R","G","G","G","G","G","G","G","G","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","G","G","G","G","R"},
  {"R","G","G","G","G","G","G","G","G","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","G","G","G","R","R"},
  {"R","G","G","G","G","G","G","G","G","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","G","G","G","R","R"},
  {"R","G","G","G","G","G","G","G","G","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","G","G","G","R","R"},
  {"R","G","G","G","G","G","G","G","G","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","G","G","G","R","R"},
  {"R","G","G","G","G","G","G","G","G","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","G","G","G","G","R"},
  {"R","G","G","G","G","G","G","G","G","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","G","G","G","G","R"},
  {"R","R","R","G","G","G","G","G","G","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","G","G","G","G","R"},
  {"R","R","R","G","G","G","G","G","G","G","G","G","G","W","W","W","W","W","W","W","G","G","G","G","G","G","G","G","G","R"},
  {"R","R","R","G","G","G","G","G","G","G","G","G","G","W","W","W","W","W","W","W","G","G","G","G","G","G","G","G","G","R"},
  {"R","G","G","G","G","G","G","G","G","G","G","G","W","W","W","W","W","W","W","W","W","G","G","G","G","G","G","G","G","R"},
  {"R","G","G","G","G","G","G","G","G","G","G","G","W","W","O","W","W","W","W","W","W","G","G","G","G","G","G","G","G","R"},
  {"R","G","G","G","G","G","G","G","G","G","G","W","W","W","W","W","W","W","W","W","W","W","G","G","G","G","G","G","G","R"},
  {"R","G","G","G","G","R","R","R","R","R","R","W","W","W","W","W","W","W","W","W","W","W","G","G","R","G","G","G","G","R"},
  {"R","G","G","G","G","R","R","R","R","R","R","W","W","W","W","W","W","W","W","W","W","W","R","R","R","R","G","G","R","R"},
  {"R","G","G","G","G","R","R","R","R","R","R","G","W","W","O","W","W","W","W","W","W","R","R","R","R","R","R","G","R","R"},
  {"R","R","R","R","R","R","R","R","R","R","R","R","R","R","R","R","R","R","R","R","R","R","R","R","R","R","R","R","R","R"},
  }
  orientation = "W";

}
void Testground::move_forward(){
  
}
