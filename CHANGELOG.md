## v2.0.0

- **New:** added an **Only After Minimum Percent** death mode switch. Turn it
  off to press the chosen key on every death, or leave it on to require the
  configured percentage.
- **New:** dependent Geode settings are now grayed out and show a red message
  explaining which parent feature must be enabled.
- **Changed:** disabling the master switch now locks every dependent setting
  and hides the in-level indicator without clearing saved values.
- **Changed:** QOLMod settings now gray out unavailable controls and display a
  clear red status message.
- **Changed:** Eclipse controls now reject changes while their required parent
  setting is disabled.
- **Changed:** refreshed the settings layout, descriptions, website, and
  documentation for the new death modes.
- **Changed:** removed repeated source, Discord, and website links from the
  in-game description because Geode already displays them as buttons.

## v1.9.2

- **New:** added the official Key Remapper Discord community link to the Geode
  mod details page.
- **Documentation:** added the Discord invite to the README and in-game About
  page.

## v1.9.1

- **Fixed:** added the Key Remapper logo to its QOLMod category button.
- **Fixed:** QOLMod now loads the icon from the mod's extracted `logo.png`
  instead of showing a text-only category.

## v1.9.0

- **New:** added a configurable minimum percentage for the death key action.
- **Changed:** the death key now presses only when the player dies after
  reaching the selected minimum percentage.
- **New:** added a clear **Death After %** field and a live threshold summary to
  the Eclipse tab.
- **New:** added an optional Key Remapper category to QOLMod **2.8.6** or newer.
- **New:** QOLMod can control the main switch, automatic actions, target
  percentages, level scope, and indicator visibility.
- **New:** added a **Choose Keys & More** button to the QOLMod category for
  settings that require Geode's key picker.

## v1.8.0

- **New:** added an optional key press when the player dies.
- **New:** added an optional key press when a level is completed.
- **New:** death and level-complete actions have separate enable switches and
  configurable keys.
- **Changed:** reorganized the Geode settings into clear titled sections.
- **Changed:** redesigned the Eclipse tab with readable section labels and
  live summaries for every automatic action.
- **Changed:** replaced the unclear **KR %**, **KR X**, and **KR Y** Eclipse
  field names with **Target %**, **Indicator X**, and **Indicator Y**.

## v1.7.0

- **New:** added an optional automatic key press at a chosen level percentage.
- **New:** added a target percentage setting from **1%** to **100%**.
- **New:** added a configurable key for the percentage action.
- **New:** added the percentage toggle, target field, and action summary to
  the Eclipse Key Remapper tab.
- **Changed:** the percentage action fires once after crossing the target and
  resets with the level attempt.

## v1.6.6

- **Fixed:** shortened the Eclipse indicator position field labels to
  **KR X** and **KR Y**.

## v1.6.5

- **New:** added an optional Key Remapper settings tab to Eclipse.
- **New:** Eclipse can now control the enabled state, activity scopes,
  indicator visibility, and indicator position.
- **New:** added a button in Eclipse that opens the Geode key settings.
- **Fixed:** prevented identical trigger and output keys from repeatedly
  sending input.
- **Fixed:** the output key is now released correctly if settings change while
  the trigger is held.
- **Changed:** prefixed the indicator node ID for better mod compatibility.

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
