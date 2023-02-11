# Tri-State Switch Component for ESPHome
This component is useful in scenarios where you want to retain the ability to control a device with a physical button while also having the ability to control it programatically, therefore making it a three-way switch, or Tri-Switch.  This component accomplishes programmatic control of the switch without interfering with the physical use of the button.

The The Tri-State switch can be controlled like any other entity in Home Assistant that can be controlled either by a manual button connected to a GPIO pin, a dashboard toggle switch, automation or script.


## Base Tri-Switch Configuration
```
switch:
  - platform: tri_state
    name: "Tri-State Switch"
    id: tri_state_switch
    pin: <GPIO_PIN_NUMBER>
    on_state: <ON_STATE>
```

Configuration variables:

  - **pin:** is the GPIO pin number that the switch is connected to.  
  - **on_state:** is either true or false, depending on whether the switch turns on with a high signal or low signal.  
  - *inherits other configuration variables from <a href="https://esphome.io/components/switch/index.html"><b>switch</b></a>.

## Example

Here's an example configuration for a Tri-State Switch connected to GPIO pin 5 and turning on with a high signal:

```
switch:
  - platform: tri_state
    name: "Tri-State Switch"
    id: tri_state_switch
    pin: 5
    on_state: true
```
