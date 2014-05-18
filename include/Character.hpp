#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include "Core.hpp"
#include "Timeline.hpp"

class Character
{
    public:
        enum Emotion
        {
            Afraid,
            Betrayed,
            Conflicted,
            Happy,
            Indignant,
            Neutral,
            Sad
        };
   
        enum Gender
        {
            Female,
            Neither,
            Male
        };

        enum Type
        {
            Enoi,
            Human,
            Unknown
        };

        Character(const std::string& name, const Type& species){};
        ~Character(){};

        void die();
        void speak(const std::string& words);
        void think(const std::string& words);
        void think(Event* memory);
        
        Emotion* getEmotion();
        Gender* getGender();
        std::string* getName();
        Type* getType();
        
        void setEmotion(const Emotion& feeling);
        void setGender(const Gender& gender){};
        void setName(const std::string& name);
        void setType(const Type& species);
        
    private:
        Emotion mEmotion;
        std::string mName;
        Type mType;
};

Character* Narrator;

#endif // CHARACTER_HPP
