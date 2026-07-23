#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include <Geode/ui/GeodeUI.hpp>
#include <eclipse.eclipse-menu/include/eclipse.hpp>

#ifdef GEODE_IS_WINDOWS
#include <Windows.h>
#endif

using namespace geode::prelude;

namespace {

#ifdef GEODE_IS_WINDOWS
    UINT activeOutputVk = 0;

    UINT keyCodeToVk(cocos2d::enumKeyCodes key) {
        using namespace cocos2d;
        switch (key) {
            case KEY_Zero: return '0'; case KEY_One: return '1'; case KEY_Two: return '2';
            case KEY_Three: return '3'; case KEY_Four: return '4'; case KEY_Five: return '5';
            case KEY_Six: return '6'; case KEY_Seven: return '7'; case KEY_Eight: return '8';
            case KEY_Nine: return '9';

            case KEY_A: return 'A'; case KEY_B: return 'B'; case KEY_C: return 'C';
            case KEY_D: return 'D'; case KEY_E: return 'E'; case KEY_F: return 'F';
            case KEY_G: return 'G'; case KEY_H: return 'H'; case KEY_I: return 'I';
            case KEY_J: return 'J'; case KEY_K: return 'K'; case KEY_L: return 'L';
            case KEY_M: return 'M'; case KEY_N: return 'N'; case KEY_O: return 'O';
            case KEY_P: return 'P'; case KEY_Q: return 'Q'; case KEY_R: return 'R';
            case KEY_S: return 'S'; case KEY_T: return 'T'; case KEY_U: return 'U';
            case KEY_V: return 'V'; case KEY_W: return 'W'; case KEY_X: return 'X';
            case KEY_Y: return 'Y'; case KEY_Z: return 'Z';

            case KEY_F1: return VK_F1; case KEY_F2: return VK_F2; case KEY_F3: return VK_F3;
            case KEY_F4: return VK_F4; case KEY_F5: return VK_F5; case KEY_F6: return VK_F6;
            case KEY_F7: return VK_F7; case KEY_F8: return VK_F8; case KEY_F9: return VK_F9;
            case KEY_F10: return VK_F10; case KEY_F11: return VK_F11; case KEY_F12: return VK_F12;

            case KEY_Space: return VK_SPACE;
            case KEY_Escape: return VK_ESCAPE;
            case KEY_Tab: return VK_TAB;
            case KEY_Backspace: return VK_BACK;
            case KEY_Enter: return VK_RETURN;
            case KEY_Insert: return VK_INSERT;
            case KEY_Delete: return VK_DELETE;
            case KEY_Home: return VK_HOME;
            case KEY_End: return VK_END;
            case KEY_PageUp: return VK_PRIOR;
            case KEY_PageDown: return VK_NEXT;

            case KEY_Up: return VK_UP;
            case KEY_Down: return VK_DOWN;
            case KEY_Left: return VK_LEFT;
            case KEY_Right: return VK_RIGHT;

            case KEY_CapsLock: return VK_CAPITAL;
            case KEY_ScrollLock: return VK_SCROLL;
            case KEY_Numlock: return VK_NUMLOCK;
            case KEY_PrintScreen: return VK_SNAPSHOT;
            case KEY_Pause: return VK_PAUSE;

            case KEY_Shift: return VK_SHIFT;
            case KEY_LeftShift: return VK_LSHIFT;
            case KEY_RightShift: return VK_RSHIFT;
            case KEY_Control: return VK_CONTROL;
            case KEY_LeftControl: return VK_LCONTROL;
            case KEY_RightContol: return VK_RCONTROL;
            case KEY_Alt: return VK_MENU;
            case KEY_LeftMenu: return VK_LMENU;
            case KEY_RightMenu: return VK_RMENU;

            case KEY_LeftWindowsKey: return VK_LWIN;
            case KEY_RightWindowsKey: return VK_RWIN;
            case KEY_ApplicationsKey: return VK_APPS;

            case KEY_NumPad0: return VK_NUMPAD0; case KEY_NumPad1: return VK_NUMPAD1;
            case KEY_NumPad2: return VK_NUMPAD2; case KEY_NumPad3: return VK_NUMPAD3;
            case KEY_NumPad4: return VK_NUMPAD4; case KEY_NumPad5: return VK_NUMPAD5;
            case KEY_NumPad6: return VK_NUMPAD6; case KEY_NumPad7: return VK_NUMPAD7;
            case KEY_NumPad8: return VK_NUMPAD8; case KEY_NumPad9: return VK_NUMPAD9;
            case KEY_Multiply: return VK_MULTIPLY;
            case KEY_Add: return VK_ADD;
            case KEY_Subtract: return VK_SUBTRACT;
            case KEY_Decimal: return VK_DECIMAL;
            case KEY_Divide: return VK_DIVIDE;

            case KEY_Semicolon: return VK_OEM_1;
            case KEY_Apostrophe: return VK_OEM_7;
            case KEY_Slash: return VK_OEM_2;
            case KEY_OEMEqual: return VK_OEM_PLUS;
            case KEY_OEMMinus: return VK_OEM_MINUS;
            case KEY_LeftBracket: return VK_OEM_4;
            case KEY_Backslash: return VK_OEM_5;
            case KEY_RightBracket: return VK_OEM_6;
            case KEY_GraveAccent: return VK_OEM_3;
            case KEY_OEMComma: return VK_OEM_COMMA;
            case KEY_OEMPeriod: return VK_OEM_PERIOD;

            default: return 0;
        }
    }

    bool isExtendedVk(UINT vk) {
        switch (vk) {
            case VK_UP: case VK_DOWN: case VK_LEFT: case VK_RIGHT:
            case VK_HOME: case VK_END: case VK_PRIOR: case VK_NEXT:
            case VK_INSERT: case VK_DELETE: case VK_NUMLOCK:
            case VK_RCONTROL: case VK_RMENU: case VK_DIVIDE:
                return true;
            default:
                return false;
        }
    }

    void sendKeyEvent(UINT vk, bool down) {
        if (!vk) return;

        INPUT input{};
        input.type = INPUT_KEYBOARD;
        input.ki.wVk = static_cast<WORD>(vk);
        input.ki.dwFlags = down ? 0 : KEYEVENTF_KEYUP;
        if (isExtendedVk(vk)) {
            input.ki.dwFlags |= KEYEVENTF_EXTENDEDKEY;
        }
        SendInput(1, &input, sizeof(INPUT));
    }
#endif

    bool scopeAllows() {
        auto gm = GameManager::sharedState();
        if (gm->getEditorLayer()) {
            return Mod::get()->getSettingValue<bool>("scope-editor");
        }
        if (gm->getPlayLayer()) {
            return Mod::get()->getSettingValue<bool>("scope-gameplay");
        }
        return Mod::get()->getSettingValue<bool>("scope-menus");
    }

    std::string describeBinding(std::vector<Keybind> const& trig, std::vector<Keybind> const& out) {
        auto name = [](std::vector<Keybind> const& v) {
            return v.empty() ? std::string("(none)") : v.front().toString();
        };
        return fmt::format("{} -> {}", name(trig), name(out));
    }

    void checkConflictAndNotify() {
        auto trig = Mod::get()->getSettingValue<std::vector<Keybind>>("trigger-key");
        auto out = Mod::get()->getSettingValue<std::vector<Keybind>>("output-key");

        if (!trig.empty() && !out.empty() && trig.front() == out.front()) {
            Notification::create(
                "Key Remapper: Trigger Key and Also Presses are the same key",
                NotificationIcon::Warning, 3.f
            )->show();
            return;
        }

        Notification::create(
            fmt::format("Key Remapper: {}", describeBinding(trig, out)),
            NotificationIcon::Info, 2.f
        )->show();
    }

    constexpr auto INDICATOR_ID = "key-remapper-indicator"_spr;

    void repositionIndicator(cocos2d::CCNode* label) {
        auto x = Mod::get()->getSettingValue<double>("indicator-x");
        auto y = Mod::get()->getSettingValue<double>("indicator-y");
        label->setPosition(ccp(static_cast<float>(x), static_cast<float>(y)));
    }

    void updateIndicatorText(cocos2d::CCLabelBMFont* label) {
        auto trig = Mod::get()->getSettingValue<std::vector<Keybind>>("trigger-key");
        auto out = Mod::get()->getSettingValue<std::vector<Keybind>>("output-key");
        label->setString(describeBinding(trig, out).c_str());
    }

    cocos2d::CCLabelBMFont* findIndicator() {
        auto pl = GameManager::sharedState()->getPlayLayer();
        if (!pl || !pl->m_uiLayer) return nullptr;
        return typeinfo_cast<cocos2d::CCLabelBMFont*>(pl->m_uiLayer->getChildByID(INDICATOR_ID));
    }

    void flashIndicator() {
        auto label = findIndicator();
        if (!label) return;
        label->stopAllActions();
        label->setColor(cocos2d::ccc3(255, 255, 255));
        label->setOpacity(255);
        label->runAction(cocos2d::CCFadeTo::create(0.35f, 160));
    }

    void addEclipseFloatSetting(
        eclipse::MenuTab const& tab,
        char const* settingId,
        char const* componentId
    ) {
        auto mod = Mod::get();
        auto setting = mod->getSetting(settingId);
        if (!setting) return;

        auto configId = std::string(componentId);
        auto input = tab.addInputFloat(
            configId,
            setting->getDisplayName(),
            [mod, settingId, configId](float value) {
                mod->setSettingValue<double>(settingId, value);
                eclipse::config::set<double>(configId, value);
            }
        );
        input.setDescription(setting->getDescription().value_or(""));
        input.setFormat("%.0f");

        eclipse::config::set<double>(
            configId,
            mod->getSettingValue<double>(settingId)
        );

        listenForSettingChanges<double>(settingId, [configId](double value) {
            eclipse::config::set<double>(configId, value);
        });
    }

    void addEclipseToggle(eclipse::MenuTab const& tab, char const* settingId) {
        auto setting = Mod::get()->getSetting(settingId);
        if (setting) {
            tab.addModSettingToggle(setting);
        }
    }

    void registerEclipseTab() {
        auto tab = eclipse::MenuTab::find("Key Remapper");

        auto binding = tab.addLabel(describeBinding(
            Mod::get()->getSettingValue<std::vector<Keybind>>("trigger-key"),
            Mod::get()->getSettingValue<std::vector<Keybind>>("output-key")
        ));

        auto updateBinding = [binding] {
            binding.setText(describeBinding(
                Mod::get()->getSettingValue<std::vector<Keybind>>("trigger-key"),
                Mod::get()->getSettingValue<std::vector<Keybind>>("output-key")
            ));
        };

        listenForSettingChanges<std::vector<Keybind>>(
            "trigger-key",
            [updateBinding](std::vector<Keybind>) { updateBinding(); }
        );
        listenForSettingChanges<std::vector<Keybind>>(
            "output-key",
            [updateBinding](std::vector<Keybind>) { updateBinding(); }
        );

        tab.addButton("Configure Keys", [] {
            openSettingsPopup(Mod::get());
        }).setDescription("Open the Geode settings to choose the trigger and output keys.");

        addEclipseToggle(tab, "enabled");
        addEclipseToggle(tab, "scope-gameplay");
        addEclipseToggle(tab, "scope-editor");
        addEclipseToggle(tab, "scope-menus");
        addEclipseToggle(tab, "show-indicator");
        addEclipseFloatSetting(tab, "indicator-x", "KR X");
        addEclipseFloatSetting(tab, "indicator-y", "KR Y");
    }

}

class $modify(KeyRemapperPlayLayer, PlayLayer) {
    bool init(GJGameLevel* level, bool useReplay, bool dontCreateObjects) {
        if (!PlayLayer::init(level, useReplay, dontCreateObjects)) return false;

        if (m_uiLayer) {
            auto label = CCLabelBMFont::create("", "chatFont.fnt");
            label->setID(INDICATOR_ID);
            label->setScale(0.6f);
            label->setOpacity(160);
            label->setAnchorPoint(ccp(0.f, 0.f));
            label->setZOrder(100);
            updateIndicatorText(label);
            repositionIndicator(label);
            label->setVisible(Mod::get()->getSettingValue<bool>("show-indicator"));
            m_uiLayer->addChild(label);
        }

        return true;
    }
};

$on_mod(Loaded) {
    listenForSettingChanges<std::vector<Keybind>>("trigger-key", [](std::vector<Keybind>) {
        checkConflictAndNotify();
        if (auto label = findIndicator()) updateIndicatorText(label);
    });
    listenForSettingChanges<std::vector<Keybind>>("output-key", [](std::vector<Keybind>) {
        checkConflictAndNotify();
        if (auto label = findIndicator()) updateIndicatorText(label);
    });
    listenForSettingChanges<double>("indicator-x", [](double) {
        if (auto label = findIndicator()) repositionIndicator(label);
    });
    listenForSettingChanges<double>("indicator-y", [](double) {
        if (auto label = findIndicator()) repositionIndicator(label);
    });
    listenForSettingChanges<bool>("show-indicator", [](bool visible) {
        if (auto label = findIndicator()) label->setVisible(visible);
    });

    listenForKeybindSettingPresses(
        "trigger-key",
        [](Keybind const& trigger, bool down, bool repeat, double) {
#ifdef GEODE_IS_WINDOWS
            if (!down) {
                if (activeOutputVk) {
                    sendKeyEvent(activeOutputVk, false);
                    activeOutputVk = 0;
                }
                return;
            }
#endif

            if (repeat) return;
            if (!Mod::get()->getSettingValue<bool>("enabled")) return;
            if (!scopeAllows()) return;

            auto outputs = Mod::get()->getSettingValue<std::vector<Keybind>>("output-key");
            if (outputs.empty()) return;
            if (outputs.front() == trigger) return;

#ifdef GEODE_IS_WINDOWS
            auto outputVk = keyCodeToVk(outputs.front().key);
            if (!outputVk) return;

            if (activeOutputVk) {
                sendKeyEvent(activeOutputVk, false);
            }
            sendKeyEvent(outputVk, true);
            activeOutputVk = outputVk;
#endif

            flashIndicator();
        }
    );

    Loader::get()->queueInMainThread(registerEclipseTab);
}
