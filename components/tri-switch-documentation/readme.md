# Tri-State Switch Component for ESPHome
This component is useful in scenarios where you want to retain the ability to control a device with a physical button while also having the ability to control it programatically.  This component accomplishes this without interfering with the physical use of the button.

The The Tri-State switch works as an entity in Home Assistant that can be controlled either by a manual button connected to a GPIO pin or by a dashboard toggle switch.


## Base Tri-Switch Configuration
To add the Tri-State Switch component to your ESPHome setup, add the following to your esphome.yaml file:

```
switch:
  - platform: tri_state
    name: "Tri-State Switch"
    id: tri_state_switch
    pin: <GPIO_PIN_NUMBER>
    on_state: <ON_STATE>
```

Configuration variables:

<GPIO_PIN_NUMBER> is the GPIO pin number that the switch is connected to.
<ON_STATE> is either true or false, depending on whether the switch turns on with a high signal or low signal.

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
