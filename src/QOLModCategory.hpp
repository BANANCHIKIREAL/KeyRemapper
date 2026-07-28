#pragma once

#include <Geode/cocos/menu_nodes/CCMenu.h>
#include <Geode/loader/Dispatch.hpp>
#include <Geode/loader/Event.hpp>
#include <ccTypes.h>

// QOLMod extension API v1:
// https://github.com/TheSillyDoggo/GeodeMenu/blob/main/include/CategoryExt.hpp
#define MY_MOD_ID "thesillydoggo.qolmod"

namespace qolmod::ext {
    using CategoryCreateFunc = std::function<void(cocos2d::CCMenu*)>;

    struct CategoryData {
        unsigned int apiVersion = 1;
        std::string displayName;
        std::string iconSpr;
        std::string categoryID;
        CategoryCreateFunc customFunc = nullptr;
    };

    inline void addCustomCategory(CategoryData data)
        GEODE_EVENT_EXPORT_NORES(&addCustomCategory, (data));
}

#undef MY_MOD_ID
