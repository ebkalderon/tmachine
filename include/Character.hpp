#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Core.hpp"
#include "Timeline.hpp"

class Character
{
    public:
        enum Emotion
        {
            Afraid,
            Awed,
            Betrayed,
            Confident,
            Conflicted,
            Curious,
            FeigningInterest,
            Happy,
            Indignant,
            Irritated,
            Neutral,
            Offended,
            Patient,
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
            Morlock,
            Unknown
        };

        Character(const std::string& name, const Type& species);
        ~Character();

        void die();
        void die(const std::string& causeOfDeath);
        void faint(const bool& unconscious);
        void laugh();
        void speak(const std::string& words);
        void smile();
        void think(const std::string& words);
        void think(Event memory, std::vector<Character*> characters, const std::string& location);
        
        std::string getEmotion();
        Gender getGender();
        std::string getName();
        Type getType();
        
        void setEmotion(const Emotion& feeling);
        void setGender(const Gender& gender){};
        void setName(const std::string& name);
        void setType(const Type& species);
        
    private:
        bool mConscious;
        Emotion mEmotion;
        std::string mName;
        Type mType;
};

#endif // CHARACTER_HPP
