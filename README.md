# Key Remapper

> Press one key. Send another. Keep full control over where it happens.

**Key Remapper** is a lightweight [Geode](https://geode-sdk.org/) mod for
Geometry Dash on Windows. It lets one configurable trigger key send a second
system-level key press at the same time.

Created by **BANANCHIKIREAL**.

**Source code:** [github.com/BANANCHIKIREAL/KeyRemapper](https://github.com/BANANCHIKIREAL/KeyRemapper)

## How it works

Choose a **Trigger Key** and an **Also Presses** key in the mod settings.
Whenever the trigger goes down or comes back up, Key Remapper sends the same
event for the output key.

For example, with the default binding:

```text
Up  →  Tab
```

Pressing and holding **Up** also presses and holds **Tab**. Releasing **Up**
releases **Tab**.

The original trigger is never blocked. It still performs its normal Geometry
Dash action; the mod simply adds the configured output key.

## Features

- Configurable trigger and output keys.
- Real Windows key events, including matching key-down and key-up behavior.
- Separate activity controls for levels, the editor, and menus.
- A movable in-level indicator showing the active binding.
- Instant indicator updates when a setting changes.
- A short indicator flash whenever the remap fires.
- Conflict warnings when both sides use the same key.
- A master switch that disables remapping without clearing your configuration.
- An optional settings tab inside Eclipse 1.9.4 or newer.

## Quick start

1. Open the Geode mod list from Geometry Dash.
2. Find **Key Remapper** and select its settings button.
3. Set **Trigger Key** to the key you want to press yourself.
4. Set **Also Presses** to the key the mod should send.
5. Choose where the remap is allowed to run.
6. Enter a level and test the binding.

Changes take effect immediately. You do not need to restart the game.

## Eclipse integration

When **Eclipse 1.9.4 or newer** is installed, its menu contains a
**Key Remapper** tab. From there you can change the enabled state, activity
scopes, indicator visibility, and indicator position.

The tab also displays the current binding and provides a **Configure Keys**
button. Key selection opens in the native Geode settings because the Eclipse
API does not provide a keybind picker. Eclipse is optional; Key Remapper works
normally without it.

## Settings

| Setting | Default | Description |
| --- | --- | --- |
| **Enabled** | On | Enables or disables the remap without resetting anything. |
| **Trigger Key** | Up | The physical key that activates the remap. |
| **Also Presses** | Tab | The additional key sent by the mod. |
| **Active in Levels** | On | Allows remapping in normal and practice gameplay. |
| **Active in Editor** | On | Allows remapping inside the level editor. |
| **Active in Menus** | On | Allows remapping everywhere outside levels and the editor. |
| **Show Indicator** | On | Shows the current binding while playing a level. |
| **Indicator X** | 50 | Sets the indicator's horizontal screen position. |
| **Indicator Y** | 50 | Sets the indicator's vertical screen position. |

## Indicator

The in-level indicator displays the active mapping in this format:

```text
Up -> Tab
```

Use **Indicator X** and **Indicator Y** to place it anywhere on screen. Turn
off **Show Indicator** if you prefer a completely clean HUD. Changing this
option while a level is open updates the indicator immediately.

## Installation

1. Install Geode for Geometry Dash.
2. Place `bananchikireal.keyremapper.geode` in the game's `geode/mods`
   directory.
3. Start or restart Geometry Dash.
4. Enable **Key Remapper** from the Geode mod list.

## Compatibility

- **Platform:** Windows
- **Geometry Dash:** 2.2081
- **Geode:** 5.8.2

## Troubleshooting

### The output key is not being pressed

- Make sure **Enabled** is turned on.
- Check that the current area is enabled under **Active in Levels**,
  **Active in Editor**, or **Active in Menus**.
- Confirm that **Also Presses** is not empty.

### The indicator is missing

- Turn on **Show Indicator**.
- Make sure **Indicator X** and **Indicator Y** place it inside the visible
  screen area.
- The indicator only appears while a level is open.

### A conflict warning appears

The trigger and output are set to the same key. Choose two different keys;
sending a key to itself does not create a useful remap.

## Important behavior

- Key Remapper adds an output press; it does not suppress the original input.
- The output is sent as a Windows system key event.
- Disabling the indicator does not disable the remap.
- Disabling the mod's **Enabled** setting keeps all other settings saved.

---

**Key Remapper** · Created by **BANANCHIKIREAL**
