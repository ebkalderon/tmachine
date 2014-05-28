#include "Character.hpp"

// These are string versions of the 3 core enums, intended for text output.
static const char *strGender[] = { "female", "neither", "male" };
static const char *strEmotion[] = { "afraid", "awestruck", "feeling betrayed", "cautious", "cheerful", "confident", "confused", "curious", "determined", "disbelieving", "feigning interest", "indignant", "irritated", "feeling neutral", "offended", "patient", "puzzled", "sad", "in deep thought" };  
static const char *strType[] = { "Eloi", "Human", "Morlock", "unknown" };

Character::Character(const std::string& name, const Type& species)
{
    mEmotion = Emotion::Neutral;
    mName = name;
    mType = species;
    mConscious = true;
    mEyesOpen = 1;
}

Character::~Character()
{
    // Dummy destructor...
}

void Character::action(const std::string& verb, Object* object)
{
    if (mConscious)
        std::cout << AnsiColors.bold << mName << " " << verb << " " << object->getName() << ".\n" << AnsiColors.normal;
}

void Character::die()
{
    // This character died of unknown causes or reasons.
    std::cout << AnsiColors.red << AnsiColors.bold << mName << " has mysteriously died.\n";
}

void Character::die(const std::string& causeOfDeath)
{
    std::cout << AnsiColors.red << AnsiColors.bold << mName << " has died of " << causeOfDeath << ".\n";
}

void Character::faint(const bool& unconscious)
{
    mConscious = unconscious;
    mEyesOpen = !mConscious;
    std::cout << AnsiColors.red << AnsiColors.bold << mName << (unconscious ? " has fainted.\n" : " has regained consciousness.\n");
}

void Character::frown()
{
    if (mConscious)
        std::cout << AnsiColors.bold << mName << " frowns.\n" << AnsiColors.normal;
}

void Character::hold(Object* object)
{
    std::cout << AnsiColors.bold << mName << " holds the " << object->getName() << ".\n" << AnsiColors.normal;
}

void Character::laugh()
{
    if (mConscious)
        std::cout << AnsiColors.bold << mName << " laughs.\n" << AnsiColors.normal;
}

void Character::lookAt(Character* person)
{
    if (mConscious)
        std::cout << AnsiColors.bold << mName << " looks at " << person->getName() << ".\n" << AnsiColors.normal;
}

void Character::lookAt(Object* object)
{
    if (mConscious)
        std::cout << AnsiColors.bold << mName << " looks at " << object->getName() << ".\n" << AnsiColors.normal;
}

void Character::listen(Character* speaker)
{
    if (mConscious)
        std::cout << AnsiColors.bold << mName << " is listening attentively to " << speaker->getName() << ".\n" << AnsiColors.normal;
}

void Character::openEyes(const int& open)
{
    mEyesOpen = open;
    std::cout << AnsiColors.bold << mName;

    if (open == 0)
        std::cout << "'s eyes close.\n" << AnsiColors.normal;
    else if (open == 1)
        std::cout << "'s eyes open.\n" << AnsiColors.normal;
    else
        std::cout << " winks.\n" << AnsiColors.normal;
}

void Character::smile()
{
    if (mConscious)
        std::cout << AnsiColors.bold << mName << " smiles.\n" << AnsiColors.normal;
}

void Character::speak(const std::string& words)
{
    // Note there is a '\n' at the end. Multi-line communications should issue
    // multiple speak() calls.

    if (mConscious)
    {
       // When speaking, names are colored bold blue and the text is normal.
       std::cout << AnsiColors.blue << AnsiColors.bold  << mName << " says: " << AnsiColors.normal << "\"" << words << "\"\n";
    }
}

void Character::think(const std::string& words)
{
    // Note there is a '\n' at the end. Multi-line communications should issue
    // multiple think() calls.

    // When speaking, names and text are colored bold italic green.
    std::cout << AnsiColors.green << AnsiColors.italic << mName << " thought: " << words << "\n" << AnsiColors.normal;
}

void Character::think(Event memory, std::vector<Character>* characters, std::vector<Object>* objects, const std::string& location)
{
    // Execute an Event without direct access to the Timeline.
    std::cout << AnsiColors.green << AnsiColors.italic << mName << " reminisces...\n" << AnsiColors.normal;
    Event tmpEvent = memory;
    tmpEvent(characters, objects, location);
    std::cout << AnsiColors.green << AnsiColors.italic << mName << " snaps out of his thought.\n" << AnsiColors.normal;
}

std::string Character::getGender()
{
    return strGender[mGender];
}

std::string Character::getEmotion()
{
    return strEmotion[mEmotion];
}

std::string Character::getName()
{
    return mName;
}

std::string Character::getType()
{
    return strType[mType];
}

void Character::setGender(const Gender& gender)
{
    mGender = gender;
}

void Character::setEmotion(const Emotion& feeling)
{
    mEmotion = feeling;
    std::cout << AnsiColors.bold << mName << " is " << getEmotion() << ".\n" << AnsiColors.normal;
}
