#include "Chapter01.hpp"
#include "Timeline.hpp"

Chapter01::~Chapter01()
{
    // Dummy destructor...
}

void dinnerParty(std::vector<Character*> characters, const std::string& location)
{
    std::cout << characters[1]->getName() << " is having a dinner party with his fellow scientists, friends, and colleagues.\n\n";

    // Define our characters.
    Character filby("Filby", Character::Type::Human);
    filby.setGender(Character::Gender::Male);
    filby.setEmotion(Character::Emotion::Irritated);

    Character medicalMan("Medical Man", Character::Type::Human);
    medicalMan.setGender(Character::Gender::Male);
    medicalMan.setEmotion(Character::Emotion::Neutral);

    Character psychologist("Psychologist", Character::Type::Human);
    psychologist.setGender(Character::Gender::Male);
    psychologist.setEmotion(Character::Emotion::Neutral);

    std::cout << std::endl;

    // The scholars are discussing over dinner.
    medicalMan.speak("What's that is nonsense?");
    psychologist.speak("He thinks that Time's only a kind of Space.");
    characters[1]->setEmotion(Character::Emotion::Patient);
    characters[1]->speak("It's not thinking; it's knowledge.");
    filby.speak("Foppish affectation.");
    characters[0]->setEmotion(Character::Emotion::FeigningInterest);
    characters[0]->think("Still harping upon his wrongs.");
    psychologist.speak("Kant——");
    filby.setEmotion(Character::Emotion::Indignant);
    filby.speak("Confound Kant! I've got experimental proof of it. I'm not a metaphysician.");
    filby.speak("It's the most promising departure in experimental work that has ever been made.");
    filby.speak("It will simply revolutionize life. Heaven knows what life will be when I've carried the thing through.");
    medicalMan.setEmotion(Character::Emotion::Curious);
    medicalMan.speak("As long as it's not the water of immortality I don't mind.");
    medicalMan.speak("What is it?");
    psychologist.speak("Only a paradox.");
    characters[1]->smile();
    psychologist.speak("You have to admit that time is a spatial dimension...");
    psychologist.setEmotion(Character::Emotion::Confident);
    psychologist.speak("... and then all sorts of remarkable consequences are found inevitable.");
    psychologist.speak("Among others, that it becomes possible to travel about in time.");
    characters[1]->laugh();
    characters[1]->speak("You forget that I'm going to prove it experimentally.");
}

void Chapter01::read(std::vector<Character*> persistentCharacters, Timeline* timeline)
{
    std::cout << AnsiColors.lightMagenta << "\n<Chapter 1>\n" << AnsiColors.normal;

    timeline->insertEntry(1895, dinnerParty);
    timeline->update(persistentCharacters, "Richmond, Surry, Victorian England");
}
