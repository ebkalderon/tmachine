#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Core.hpp"
#include "Object.hpp"
#include "Timeline.hpp"

class Character
{
    public:
        enum Emotion
        {
            Afraid,
            Awed,
            Betrayed,
            Cautious,
            Cheerful,
            Confident,
            Confused,
            Curious,
            Determined,
            Disbelieving,
            FeigningInterest,
            Indignant,
            Irritated,
            Neutral,
            Offended,
            Patient,
            Puzzled,
            Sad,
            Thoughtful
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

        void action(const std::string& verb, Object* object);
        void die();
        void die(const std::string& causeOfDeath);
        void faint(const bool& unconscious);
        void frown();
        void hold(Object* object);
        void laugh();
        void listen(Character* speaker);
        void lookAt(Character* person);
        void lookAt(Object* object);
        void openEyes(const int& open);
        void smile();
        void speak(const std::string& words);
        void think(const std::string& words);
        void think(Event memory, std::vector<Character>* characters, std::vector<Object>* objects, const std::string& location);
        
        std::string getEmotion();
        std::string getGender();
        std::string getName();
        std::string getType();
        
        void setEmotion(const Emotion& feeling);
        void setGender(const Gender& gender);
        void setName(const std::string& name);
        void setType(const Type& species);
        
    private:
        bool mConscious;
        int mEyesOpen; // 0 = closed, 1 = open, 2 = wink
        Gender mGender;
        Emotion mEmotion;
        std::string mName;
        Type mType;
};

static inline void allListen(std::vector<Character*> listeners, Character* speaker)
{
    if (listeners.size() == 1)
        listeners[0]->listen(speaker);
    else
    {
        for (unsigned int i = 0; i < listeners.size() - 1; ++i)
            std::cout << listeners[i]->getName() << ", ";

        std:: cout << "and " << listeners[listeners.size() - 1]->getName() << " listen attentively to " << speaker->getName() << ".\n";
    }
}

static inline void allLook(std::vector<Character*> watchers, Character* person)
{
    if (watchers.size() == 1)
        watchers[0]->lookAt(person);
    else
    {
        for (unsigned int i = 0; i < watchers.size() - 1; ++i)
            std::cout << watchers[i]->getName() << ", ";

        std:: cout << "and " << watchers[watchers.size() - 1]->getName() << " look at " << person->getName() << ".\n";
    }
}

static inline void allLook(std::vector<Character*> watchers, Object* object)
{
    if (watchers.size() == 1)
        watchers[0]->lookAt(object);
    else
    {
        for (unsigned int i = 0; i < watchers.size() - 1; ++i)
            std::cout << watchers[i]->getName() << ", ";

        std:: cout << "and " << watchers[watchers.size() - 1]->getName() << " look closely at " << object->getName() << ".\n";
    }
}

#endif // CHARACTER_HPP
