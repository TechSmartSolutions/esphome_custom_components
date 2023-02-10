#include "tlc59711.h"
#include "esphome/core/log.h"

namespace esphome {
namespace tlc59711 {

static const char *const TAG = "tlc59711";

void tlc59711::setup() {
  this->data_pin_->setup();
  this->data_pin_->digital_write(true);
  this->clock_pin_->setup();
  this->clock_pin_->digital_write(true);
  }

  this->pwm_amounts_.resize(this->num_chips_ * N_CHANNELS_PER_CHIP, 0);

  ESP_LOGCONFIG(TAG, "Done setting up tlc59711 output component.");
}
void tlc59711::dump_config() {
  ESP_LOGCONFIG(TAG, "tlc59711:");
  LOG_PIN("  Data Pin: ", this->data_pin_);
  LOG_PIN("  Clock Pin: ", this->clock_pin_);
  ESP_LOGCONFIG(TAG, "  Number of chips: %u", this->num_chips_);
}

void tlc59711::loop() {
  if (!this->update_)
    return;

    // push the data out, MSB first, 12 bit word per channel, 12 channels per chip
  for (int32_t ch = N_CHANNELS_PER_CHIP * num_chips_ - 1; ch >= 0; ch--) {
    uint16_t word = pwm_amounts_[ch];
    for (uint8_t bit = 0; bit < 12; bit++) {
      this->clock_pin_->digital_write(false);
      this->data_pin_->digital_write(word & 0x800);
      word <<= 1;

      this->clock_pin_->digital_write(true);
      this->clock_pin_->digital_write(true);  // TWH0>12ns, so we should be fine using this as delay
    }
  }

  this->clock_pin_->digital_write(false);

  this->update_ = false;
}

}  // namespace tlc59711
}  // namespace esphome