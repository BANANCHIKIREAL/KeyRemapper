## v1.6.4

- **New:** added the official GitHub source repository.
- **New:** added a source-code button to the Geode mod details screen.

## v1.6.3

- **Changed:** updated the mod for Geode **5.8.2**.
- **Changed:** renamed the mod ID from `dukav.keyremapper` to
  `bananchikireal.keyremapper`.
- **Changed:** added a short, dedicated `about.md` designed for Geode's
  in-game description renderer.
- **Changed:** simplified the short mod description.

## v1.6.2

- **Changed:** polished the mod logo with transparent rounded corners and a
  layered turquoise-and-gold arcade frame.
- **Changed:** updated the mod author to **BANANCHIKIREAL**.
- **Documentation:** rewrote the README with a complete feature overview,
  settings reference, installation guide, compatibility details, and
  troubleshooting.
- **Fixed:** removed the dark square pixels that appeared around the icon's
  outer corners in Geode.

## v1.6.1

- **Changed:** replaced the mod logo with a new full-size design showing the
  Up Arrow key being remapped to Tab.

## v1.6.0

- **New:** a **Show Indicator** setting that hides or shows the on-screen
  binding indicator, including while a level is already open.

## v1.5.0

- **Removed:** Mouse 4/5 support. Turned out to be unusable on the mouse it
  was tested with — many mice remap their side buttons through vendor
  software before Windows ever sees them as a real mouse button, so the
  keybind picker could never record them. Keyboard-only again.
- **New:** an on-screen indicator, visible while playing a level, showing the
  current binding (e.g. "Up -> Tab"). It flashes whenever the trigger key
  fires.
- **New:** **Indicator X** / **Indicator Y** settings to place the indicator
  wherever you want on screen.

## v1.4.0

- **New:** scope toggles — **Active in Levels / Editor / Menus** — to limit
  where the remap fires.
- **New:** Mouse 4/5 are now supported as either the Trigger Key or Also
  Presses key, not just keyboard keys.
- **New:** a warning notification if Trigger Key and Also Presses end up set
  to the same key.
- **New:** a notification shows the current binding whenever you change
  either key, so you can confirm it at a glance.

## v1.3.1

- Removed the temporary debug notifications from v1.3.0 now that the fix is
  confirmed working — the mod goes back to running silently in the background.

## v1.3.0

- Added temporary on-screen notifications when the trigger key fires, to help
  track down why the mapped key press wasn't showing any visible effect.
- Confirmed with these that the `SendInput` fix from v1.1.0 does work: the
  trigger fires and the mapped key is sent with the correct virtual-key code.

## v1.1.0

- **Fixed:** the mapped key did nothing noticeable — it was only simulated
  inside the game's own input system, which nothing in Geometry Dash actually
  reacts to by default. It's now sent as a real system-level keystroke via
  `SendInput`, so it registers everywhere, not just inside the game.
- New icon.

## v1.0.0

- Initial release.
- Configurable **Trigger Key** and **Also Presses** key, set from the mod's own settings.
- **Enabled** toggle to turn the remap on/off without losing your key choices.
- Default binding: **Up** also presses **Tab**.
