#include "Chapter01.hpp"
//#include "Book.hpp"

Chapter01::~Chapter01()
{
    // Dummy destructor...
}

/**
 * Chapter 1, The Time Traveller has a dinner party.
 * The scholars discuss science together.
 */
void dinnerParty(std::vector<Character>* characters, std::vector<Object>* objects, const std::string& location)
{
    std::cout << (*characters)[1].getName() << " is having a dinner party with his fellow scientists, friends, and colleagues.\n";

    // Define objects in the room.
    Object fireplace("living room fireplace");
    fireplace.glow = new GlowComponent(true, 1);

    Object lamps("set of incandescent lamps");
    lamps.glow = new GlowComponent(true, 16);

    std::cout << std::endl;

    // Define our characters.
    Character* timeTraveler = &(*characters)[1];

    Character filby("Filby", Character::Type::Human);
    filby.setGender(Character::Gender::Male);
    filby.setEmotion(Character::Emotion::Irritated);

    Character medicalMan("The Medical Man", Character::Type::Human);
    medicalMan.setGender(Character::Gender::Male);
    medicalMan.setEmotion(Character::Emotion::Neutral);

    Character psychologist("The Psychologist", Character::Type::Human);
    psychologist.setGender(Character::Gender::Male);
    psychologist.setEmotion(Character::Emotion::Neutral);

    std::cout << std::endl;

    // Make the characters listen to The Time Traveller.
    filby.listen(timeTraveler);
    medicalMan.listen(timeTraveler);
    psychologist.listen(timeTraveler);

    std::cout << std::endl;

    filby.speak("Let's turn off those damned electric lights, shall we?");
    lamps.glow->isLit(false);
    filby.setEmotion(Character::Emotion::Happy);
    filby.speak("Much better!");
}

void Chapter01::read(std::vector<Character>* persistentCharacters, std::vector<Object>* persistentObjects, Timeline* timeline)
{
    std::cout << AnsiColors.lightMagenta << "\n<Chapter 1>\n" << AnsiColors.normal;
    
    // Make our undidentified narrator the one speaking.
    setNarrator((*persistentCharacters)[0]);

    /*
    // Define the time machine.
    Object timeMachine("Time Machine");
    timeMachine.engine = new TimeTravelComponent(timeline);
    persistentObjects->push_back(timeMachine);
    */

    // Add our Events to the timeline
    timeline->insertEntry(1895, dinnerParty);
    timeline->update(persistentCharacters, persistentObjects, "Richmond, Surry, Victorian England");
}
