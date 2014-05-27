#include "Character.hpp"
#include "Timeline.hpp"

// These are string versions of the 3 core enums, intended for text output.
static const char *strGender[] = { "female", "neither", "male" };
static const char *strEmotion[] = { "afraid", "awed", "feeling betrayed", "confident", "conflicted", "curious", "feigning interest", "happy", "indignant", "irritated", "feeling neutral", "offended", "patient", "sad" };  
static const char *strType[] = { "Eloi", "Human", "Morlock", "unknown" };

Character::Character(const std::string& name, const Type& species)
{
    mEmotion = Emotion::Neutral;
    mName = name;
    mType = species;
    mConscious = true;
}

Character::~Character()
{
    // Dummy destructor...
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
}

void Character::laugh()
{
    std::cout << mName << " laughs.\n";
}

void Character::listen(Character* character)
{
    std::cout << mName << " is listening attentively to " << character->getName() << ".\n";
}

void Character::smile()
{
    std::cout << mName << " smiles.\n";
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
    std::cout << AnsiColors.green << AnsiColors.italic << mName << " thought: \"" << words << "\"\n";
}

void Character::think(Event memory, std::vector<Character>* characters, std::vector<Object>* objects, const std::string& location)
{
    // Execute an Event without direct access to the Timeline.
    std::cout << AnsiColors.green << AnsiColors.italic << mName << " reminisces...\n";
    Event tmpEvent = memory;
    tmpEvent(characters, objects, location);
    std::cout << AnsiColors.green << AnsiColors.italic << mName << " snaps out of his thought.\n";
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
    std::cout << mName << " is " << getEmotion() << ".\n";
}
