#include "Chapter01.hpp"
Timeline* timeSpaceContinuum;

Chapter01::~Chapter01()
{
    // Dummy destructor...
}

/**
 * Chapter 1, The Time Traveller thinks back to the
 * creation of his wonderful device.
 */
void timeMachineMemory(std::vector<Character>* characters, std::vector<Object>* objects, const std::string& location)
{
    // Define our characters.
    Character* narrator = &(*characters)[0];
    Character* timeTraveller = &(*characters)[1];

    // Define the time machine.
    Object timeMachine("Time Machine");
    timeMachine.engine = new TimeTravelComponent(timeSpaceContinuum);
    timeMachine.engine->pilot = timeTraveller;

    std::cout << std::endl;
    narrator->speak("The thing the Time Traveller held in his hand was a glittering metallic framework, scarcely larger than a small clock, and very");
    narrator->speak("delicately made. There was ivory in it, and some transparent crystalline substance.");

    // Make the time machine a persistent object.
    (*objects).push_back(timeMachine);

    sleep;
}

/**
 * Chapter 1, The Time Traveller has a dinner party.
 * The scholars discuss science together.
 */
void dinnerParty(std::vector<Character>* characters, std::vector<Object>* objects, const std::string& location)
{
    std::cout << (*characters)[1].getName() << " is having a dinner party with his fellow scientists, friends, and colleagues.\n";

    // Define objects in the room.
    Object table("large table");
    Object tobaccoJar("tobacco jar on the mantel");

    Object fireplace("living room fireplace");
    fireplace.glow = new GlowComponent(true, 1);

    Object lamps("set of incandescent lamps");
    lamps.glow = new GlowComponent(true, 16);

    Object candles("set of candles");
    candles.glow = new GlowComponent(true, 12);

    std::cout << std::endl;

    // Define our characters.
    Character* narrator = &(*characters)[0];
    Character* timeTraveller = &(*characters)[1];

    Character filby("Filby", Character::Type::Human);
    filby.setGender(Character::Gender::Male);
    filby.setEmotion(Character::Emotion::Irritated);

    Character medicalMan("The Medical Man", Character::Type::Human);
    medicalMan.setGender(Character::Gender::Male);
    medicalMan.setEmotion(Character::Emotion::Neutral);

    Character psychologist("The Psychologist", Character::Type::Human);
    psychologist.setGender(Character::Gender::Male);
    psychologist.setEmotion(Character::Emotion::Neutral);

    Character youngMan("The Young Man", Character::Type::Human);
    youngMan.setGender(Character::Gender::Male);
    youngMan.setEmotion(Character::Emotion::Curious);

    Character mayor("Provincial Mayor", Character::Type::Human);
    mayor.setGender(Character::Gender::Male);
    mayor.setEmotion(Character::Emotion::Curious);

    std::cout << std::endl;

    // Make the characters listen to the Time Traveller.
    std::vector<Character*> people = { &filby, &medicalMan, &psychologist, &youngMan, &mayor };
    allListen(people, timeTraveller);
    allLook(people, timeTraveller);
    std::cout << std::endl;

    // Begin dialogue between the Time Traveller and his guests.
    timeTraveller->speak("You must follow me carefully. I shall have to controvert one or two ideas that are almost universally accepted.");
    timeTraveller->speak("The geometry, for instance, they taught you at school is founded on a misconception.");

    filby.speak("Is not that rather a large thing to expect us to begin upon?");

    timeTraveller->speak("I do not mean to ask you to accept anything without reasonable ground for it.");
    timeTraveller->speak("You will soon admit as much as I need from you.");
    timeTraveller->speak("You know of course that a mathematical line, a line of thickness nil, has no real existence.");
    timeTraveller->speak("They taught you that? Neither has a mathematical plane. These things are mere abstractions.");

    psychologist.setEmotion(Character::Emotion::Cautious);
    psychologist.speak("That is all right.");

    timeTraveller->speak("Nor, having only length, breadth, and thickness, can a cube have a real existence.");

    filby.setEmotion(Character::Emotion::Indignant);
    filby.speak("There I object. Of course a solid body may exist. All real things—");

    timeTraveller->setEmotion(Character::Emotion::Confident);
    timeTraveller->speak("So most people think. But wait a moment. Can an *instantaneous* cube exist?");

    filby.setEmotion(Character::Emotion::Confused);
    filby.frown();
    filby.speak("Don't follow you.");

    timeTraveller->speak("Can a cube that does not last for any time at all, have a real existence?");

    filby.setEmotion(Character::Emotion::Thoughtful);

    timeTraveller->speak("Clearly, any real body must have extension in four directions: it must have Length, Breadth, Thickness, and--Duration.");
    timeTraveller->speak("But through a natural infirmity of the flesh, which I will explain to you in a moment, we incline to overlook this fact.");
    timeTraveller->speak("There are really four dimensions, three which we call the three planes of Space, and a fourth, Time.");
    timeTraveller->speak("There is, however, a tendency to draw an unreal distinction between the former three dimensions and the latter, because it happens");
    timeTraveller->speak("that our consciousness moves intermittently in one direction along the latter from the beginning to the end of our lives.");

    std::cout << std::endl;

    youngMan.think("Incredible!");
    youngMan.setEmotion(Character::Emotion::Awed);
    Object cigar("cigar");
    cigar.glow = new GlowComponent(false, 1);
    youngMan.action("tries to relight his", &cigar);
    sleep;
    youngMan.speak("That, that... very clear indeed.");

    std::cout << std::endl;

    timeTraveller->speak("Now, it is very remarkable that this is so extensively overlooked");
    timeTraveller->setEmotion(Character::Emotion::Cheerful);
    timeTraveller->speak("Really this is what is meant by the Fourth Dimension, though some people who talk about the Fourth Dimension do not know they mean it.");
    timeTraveller->speak("It is only another way of looking at Time. There is no difference between Time and any of the three dimensions of Space except that");
    timeTraveller->speak("our consciousness moves along it. But some foolish people have got hold of the wrong side of that idea.");
    timeTraveller->speak("You have all heard what they have to say about this Fourth Dimension?");

    mayor.speak("I have not.");

    timeTraveller->speak("It is simply this. That Space, as our mathematicians have it, is spoken of as having three dimensions, which one may call Length,");
    timeTraveller->speak("Breadth, and Thickness, and is always definable by reference to three planes, each at right angles to the others. But some philosophical");
    timeTraveller->speak("people have been asking why three dimensions particularly--why not another direction at right angles to the other three?--and have");
    timeTraveller->speak("even tried to construct a Four-Dimension geometry. Professor Simon Newcomb was expounding this to the New York Mathematical Society");
    timeTraveller->speak("only a month or so ago. You know how on a flat surface, which has only two dimensions, we can represent a figure of a three-dimensional");
    timeTraveller->speak("solid, and similarly they think that by models of three dimensions they could represent one of four--if they could master the");
    timeTraveller->speak("perspective of the thing. See?");

    std::cout << std::endl;

    mayor.setEmotion(Character::Emotion::Thoughtful);
    mayor.speak("I think so...");
    mayor.openEyes(0);
    sleep;
    mayor.think(".....");
    sleep;
    mayor.speak("Yes, I think I see it now.");
    mayor.openEyes(1);

    timeTraveller->speak("Well, I do not mind telling you I have been at work upon this geometry of Four Dimensions for some time.");
    timeTraveller->speak("Some of my results are curious. For instance, here is a portrait of a man at eight years old, another at fifteen, another at");
    timeTraveller->speak("seventeen, another at twenty-three, and so on. All these are evidently sections, as it were, Three-Dimensional representations of");
    timeTraveller->speak("his Four-Dimensioned being, which is a fixed and unalterable thing.");

    std::cout << std::endl;

    filby.setEmotion(Character::Emotion::FeigningInterest);
    medicalMan.setEmotion(Character::Emotion::Puzzled);
    psychologist.setEmotion(Character::Emotion::Thoughtful);
    youngMan.setEmotion(Character::Emotion::Confused);
    mayor.setEmotion(Character::Emotion::Thoughtful);

    std::cout << std::endl;

    Object diagram("paper diagram");
    timeTraveller->hold(&diagram);
    timeTraveller->speak("Scientific people know very well that Time is only a kind of Space.");
    timeTraveller->speak("Here is a popular scientific diagram, a weather record. This line I trace with my finger shows the movement of the barometer.");
    timeTraveller->speak("Yesterday it was so high, yesterday night it fell, then this morning it rose again, and so gently upward to here.");
    timeTraveller->speak("Surely the mercury did not trace this line in any of the dimensions of Space generally recognized?");
    timeTraveller->speak("But certainly it traced such a line, and that line, therefore, we must conclude was along the Time-Dimension.");

    medicalMan.speak("But...");
    medicalMan.lookAt(&fireplace);
    medicalMan.speak("if Time is really only a fourth dimension of Space, why is it, and why has it always been, regarded as something different?");
    medicalMan.speak("And why cannot we move in Time as we move about in the other dimensions of Space?");

    timeTraveller->smile();
    timeTraveller->speak("Are you sure we can move freely in Space?");
    timeTraveller->speak("Right and left we can go, backward and forward freely enough, and men always have done so.");
    timeTraveller->speak("I admit we move freely in two dimensions. But how about up and down? Gravitation limits us there.");

    medicalMan.speak("Not exactly. There are balloons.");
    timeTraveller->speak("But before the balloons, save for spasmodic jumping and the inequalities of the surface, man had no freedom of vertical movement.");
    medicalMan.speak("Still they could move a little up and down.");
    timeTraveller->speak("Easier, far easier down than up.");
    medicalMan.setEmotion(Character::Emotion::Irritated);
    medicalMan.speak("And you cannot move at all in Time, you cannot get away from the present moment.");

    std::cout << std::endl;

    timeTraveller->speak("My dear sir, that is just where you are wrong. That is just where the whole world has gone wrong.");
    medicalMan.setEmotion(Character::Emotion::Confused);
    timeTraveller->speak("We are always getting away from the present moment. Our mental existences, which are immaterial and have no dimensions, are");
    timeTraveller->speak("passing along the Time-Dimension with a uniform velocity from the cradle to the grave. Just as we should travel down if we began");
    timeTraveller->speak("our existence fifty miles above the earth's surface.");

    std::cout << std::endl;

    psychologist.speak("But the great difficulty is this. You can move about in all directions of Space, but you cannot move about in Time.");
    timeTraveller->speak("That is the germ of my great discovery. But you are wrong to say that we cannot move about in Time.");
    timeTraveller->setEmotion(Character::Emotion::Patient);
    timeTraveller->speak("For instance, if I am recalling an incident very vividly I go back to the instant of its occurrence: I become absent-minded, as");
    timeTraveller->speak("you say. I jump back for a moment. Of course we have no means of staying back for any length of Time, any more than a savage or");
    timeTraveller->speak("an animal has of staying six feet above the ground. But a civilized man is better off than the savage in this respect. He can");
    timeTraveller->speak("go up against gravitation in a balloon, and why should he not hope that ultimately he may be able to stop or accelerate his");
    timeTraveller->speak("drift along the Time-Dimension, or even turn about and travel the other way?");

    std::cout << std::endl;

    psychologist.setEmotion(Character::Emotion::Indignant);
    filby.setEmotion(Character::Emotion::Indignant);

    std::cout << std::endl;

    filby.speak("Oh, this is all--");
    timeTraveller->speak("Why not?");
    filby.speak("It's against reason.");
    timeTraveller->speak("What reason?");
    filby.speak("You can show black is white by argument, but you will never convince me.");
    timeTraveller->setEmotion(Character::Emotion::Determined);
    timeTraveller->speak("Possibly not. But now you begin to see the object of my investigations into the geometry of Four Dimensions.");
    timeTraveller->speak("Long ago I had a vague inkling of a machine--");
    youngMan.setEmotion(Character::Emotion::Awed);
    youngMan.speak("To travel through Time!");
    timeTraveller->speak("--That shall travel indifferently in any direction of Space and Time, as the driver determines.");

    std::cout << std::endl;

    // The Time Traveller reminisces about his mysterious time machine.
    timeTraveller->think(timeMachineMemory, characters, objects, "unknown location");

    std::cout << std::endl;

    filby.laugh();
    timeTraveller->speak("But I have experimental verification.");
    psychologist.setEmotion(Character::Emotion::Curious);
    psychologist.speak("It would be remarkably convenient for the historian.");
    psychologist.speak("One might travel back and verify the accepted account of the Battle of Hastings, for instance!");
    filby.setEmotion(Character::Emotion::Irritated);
    medicalMan.speak("Don't you think you would attract attention? Our ancestors had no great tolerance for anachronisms.");
    youngMan.think("One might get one's Greek from the very lips of Homer and Plato. In which case they would certainly plough you for the Little-go.");
    youngMan.think("The German scholars have improved Greek so much.");
    youngMan.speak("Then there is the future.");
    timeTraveller->listen(&youngMan);
    youngMan.speak("Just think! One might invest all one's money, leave it to accumulate at interest, and hurry on ahead!");
    narrator->speak("To discover a society erected on a strictly communistic basis.");
    psychologist.setEmotion(Character::Emotion::Indignant);
    psychologist.speak("Of all the wild extravagant theories!");
    timeTraveller->speak("Yes, so it seemed to me, and so I never talked of it until--");
    narrator->speak("Experimental verification! You are going to verify that?");
    filby.frown();
    filby.setEmotion(Character::Emotion::Indignant);
    filby.speak("The experiment!");
    psychologist.speak("Let's see your experiment anyhow, though it's all humbug, you know.");

    std::cout << std::endl;

    timeTraveller->smile();
    timeTraveller->setEmotion(Character::Emotion::Confident);
    narrator->speak("And with his hands deep in his trousers pockets, he walked slowly out of the room, and we heard his slippers shuffling down");
    narrator->speak("the long passage to his laboratory.");
    timeTraveller = NULL;

    std::cout << std::endl;

    // Make the characters listen to the Psychologist.
    std::vector<Character*> people2 = { &filby, &psychologist, &youngMan, &mayor };
    allListen(people2, &psychologist);
    std::cout << std::endl;

    psychologist.setEmotion(Character::Emotion::Curious);
    psychologist.speak("I wonder what he's got?");
    medicalMan.speak("Some sleight-of-hand trick or other.");
    narrator->speak("Filby tried to tell us about a conjurer he had seen at Burslem; but before he had finished his preface the Time Traveller came");
    narrator->speak("back, and Filby's anecdote collapsed.");

    std::cout << std::endl;

    timeTraveller = &(*characters)[1];
    timeMachineMemory(characters, objects, location);
    Object* timeMachine = &(*objects)[0];
    Object timeMachinePart("little bar");
    std::cout << AnsiColors.bold << "Its mechanisms are exposed.\n" << AnsiColors.normal;

    std::cout << std::endl;

    narrator->speak("And now I must be explicit, for this that follows--unless his explanation is to be accepted--is an absolutely unaccountable thing.");
    sleep;
    timeTraveller->lookAt(timeMachine);
    psychologist.speak("Well?");
    sleep;
    timeTraveller->speak("This little affair is only a model. It is my plan for a machine to travel through time. You will notice that it looks");
    timeTraveller->speak("singularly askew, and that there is an odd twinkling appearance about this bar, as though it was in some way unreal.");
    timeTraveller->action("points to the", &timeMachinePart);
    timeTraveller->speak("Also, here is one little white lever, and here is another.");

    std::cout << std::endl;

    medicalMan.setEmotion(Character::Emotion::Awed);
    medicalMan.lookAt(timeMachine);
    medicalMan.speak("It's beautifully made.");
    timeTraveller->setEmotion(Character::Emotion::Cheerful);
    timeTraveller->speak("It took two years to make.");
    allLook(people, timeMachine);
    allListen(people, timeTraveller);
    timeTraveller->speak("I want you clearly to understand that this lever, being pressed over, sends the machine gliding into the future, and");
    timeTraveller->speak("this other reverses the motion. This saddle represents the seat of a time traveller. Presently I am going to press the lever, and");
    timeTraveller->speak("off the machine will go. It will vanish, pass into future Time, and disappear. Have a good look at the thing. Look at the table");
    timeTraveller->speak("too, and satisfy yourselves there is no trickery. I don't want to waste this model, and then be told I'm a quack.");

    std::cout << std::endl;
    allLook(people, &table);
    std::cout << std::endl;

    filby.setEmotion(Character::Emotion::Awed);
    medicalMan.setEmotion(Character::Emotion::Awed);
    psychologist.setEmotion(Character::Emotion::Awed);
    youngMan.setEmotion(Character::Emotion::Awed);
    mayor.setEmotion(Character::Emotion::Awed);

    std::cout << std::endl;

    sleep;
    sleep;
    psychologist.think("Perhaps I should say--oh, never mind.");
    timeTraveller->setEmotion(Character::Emotion::Determined);
    timeTraveller->lookAt(&psychologist);
    timeTraveller->speak("No. Lend me your hand.");

    std::cout << std::endl;

    narrator->speak("He took that individual's hand in his own and told him to put out his forefinger.");
    timeMachine->engine->pilot = &psychologist;
    std::cout << AnsiColors.bold << psychologist.getName() << " has taken control of " << timeMachine->getName() << ".\n" << AnsiColors.normal;
    narrator->speak("So that it was the Psychologist himself who sent forth the model Time Machine on its interminable voyage.");
    timeMachine->engine->travel(1895);
    std::cout << AnsiColors.bold << "The candles rattle violently. " << AnsiColors.normal;
    candles.glow->isLit(false);
    narrator->speak("We all saw the lever turn. I am absolutely certain there was no trickery.");

    std::cout << std::endl;

    sleep;
    psychologist.setEmotion(Character::Emotion::Disbelieving);
    psychologist.lookAt(&table);
    timeTraveller->lookAt(&psychologist);
    timeTraveller->setEmotion(Character::Emotion::Cheerful);
    timeTraveller->laugh();
    timeTraveller->speak("Well?");
    psychologist.lookAt(&fireplace);
    Object pipe1("pipe");
    pipe1.glow = new GlowComponent(false, 1);
    psychologist.action("fills pipe from", &tobaccoJar);

    narrator->lookAt(timeTraveller);
    timeTraveller->lookAt(narrator);
    medicalMan.setEmotion(Character::Emotion::Disbelieving);
    medicalMan.speak("Look here, are you in earnest about this? Do you seriously believe that that machine has travelled into time?");
    timeTraveller->speak("Certainly.");
    Object pipe2("pipe");
    pipe2.glow = new GlowComponent(true, 1);
    timeTraveller->action("lights pipe from", &fireplace);
    timeTraveller->lookAt(&psychologist);
    timeTraveller->setEmotion(Character::Emotion::Patient);

    std::cout << std::endl;

    psychologist.setEmotion(Character::Emotion::Determined);
    Object cigar2("uncut cigar");
    pipe2.glow = new GlowComponent(false, 1);
    psychologist.action("tries to light", &cigar2);
    timeTraveller->speak("What is more, I have a big machine nearly finished in there--");
    narrator->think("He indicated the laboratory.");
    timeTraveller->speak("--and when that is put together I mean to have a journey on my own account.");
    filby.setEmotion(Character::Emotion::Disbelieving);
    filby.speak("You mean to say that that machine has travelled into the future?");
    timeTraveller->speak("Into the future or the past--I don't, for certain, know which.");
    sleep;

    std::cout << std::endl;

    psychologist.setEmotion(Character::Emotion::Thoughtful);
    psychologist.speak("It must have gone into the past if it has gone anywhere.");
    timeTraveller->setEmotion(Character::Emotion::Confused);
    timeTraveller->speak("Why?");
    psychologist.speak("Because I presume that it has not moved in space, and if it travelled into the future it would still be here all this time, since");
    psychologist.speak("it must have travelled through this time.");                                                                           
    timeTraveller->setEmotion(Character::Emotion::Thoughtful);
    narrator->setEmotion(Character::Emotion::Puzzled);
    narrator->speak("But if it travelled into the past it would have been visible when we came first into this room; and last Thursday when we were here;");
    narrator->speak("and the Thursday before that; and so forth!");

    std::cout << std::endl;

    filby.setEmotion(Character::Emotion::Disbelieving);
    mayor.frown();
    mayor.speak("Serious objections.");
    mayor.lookAt(timeTraveller);
    timeTraveller->speak("Not a bit.");
    timeTraveller->lookAt(&psychologist);
    timeTraveller->speak("You think. You can explain that. It's presentation below the threshold, you know, diluted presentation.");
    psychologist.speak("Of course. That's a simple point of psychology. I should have thought of it. It's plain enough, and helps the paradox delightfully.");
    psychologist.speak("We cannot see it, nor can we appreciate this machine, any more than we can the spoke of a wheel spinning, or a bullet flying");
    psychologist.speak("through the air. If it is travelling through time fifty times or a hundred times faster than we are, if it gets through a minute");
    psychologist.speak("while we get through a second, the impression it creates will of course be only one-fiftieth or one-hundredth of what it would make");
    psychologist.speak("if it were not travelling in time. That's plain enough.");
    psychologist.action("touches", &table);
    psychologist.speak("You see?");
    psychologist.laugh();

    std::cout << std::endl;

    sleep;
    sleep;
    timeTraveller->speak("What do you all think of it?");
    allLook(people, timeTraveller);
    medicalMan.think(".....");
    medicalMan.speak("It sounds plausible enough to-night, but wait until to-morrow. Wait for the common sense of the morning.");
    timeTraveller->speak("Would you like to see the Time Machine itself?");
    Object lamp("lamp");
    lamp.glow = new GlowComponent(true, 1);
    timeTraveller->action("starts to leave towards the laboratory and picks up the ", &lamp);

    medicalMan.setEmotion(Character::Emotion::Cautious);
    medicalMan.speak("Look here, are you perfectly serious? Or is this a trick--like that ghost you showed us last Christmas?");
    timeTraveller->lookAt(&medicalMan);
    timeTraveller->setEmotion(Character::Emotion::Determined);
    timeTraveller->speak("Upon that machine, I intend to explore time. Is that plain? I was never more serious in my life.");

    std::cout << std::endl;

    filby.setEmotion(Character::Emotion::Puzzled);
    medicalMan.setEmotion(Character::Emotion::Puzzled);
    psychologist.setEmotion(Character::Emotion::Puzzled);
    youngMan.setEmotion(Character::Emotion::Puzzled);
    mayor.setEmotion(Character::Emotion::Puzzled);

    std::cout << std::endl;

    filby.lookAt(narrator);
    narrator->lookAt(&filby);
    filby.openEyes(2); // Wink at the narrator!
}

void Chapter01::read(std::vector<Character>* persistentCharacters, std::vector<Object>* persistentObjects, Timeline* timeline)
{
    std::cout << AnsiColors.lightMagenta << "\n<Chapter 1>\n" << AnsiColors.normal;
    
    // Make our undidentified narrator the one speaking.
    setNarrator((*persistentCharacters)[0]);

    // Make a temporary copy of our timeline so the time machine can access it.
    timeSpaceContinuum = timeline;

    // Add our Events to the timeline.
    timeline->insertEntry(1895, dinnerParty);
    timeline->update(persistentCharacters, persistentObjects, "Richmond, Surry, Victorian England");
}
