# Design Document

> _Too long; didn't read:_ There are two major constructs in this program: book and timeline.
> Books contain an array of chapters. When a book is read, it advances from chapter to chapter sequentially. Chapters each contain plot segments, which also advance sequentially.
> Separate from this concept is the idea of a timeline, which keeps track of past, present, and future events. An event is an occurrence that must contain a setting, characters, and objects. When a chapter from the book is read, events are inserted into the timeline as described by the author.
> The time machine is an object that exists within an event and is able to modify the timeline's current year counter at will, allowing the traveler to interact with characters and objects from other time periods.

> _NOTE:_ Henceforth, the term "TTM" will refer to _The Time Machine_.

### Defining a Book, Plot, and Chapters
1. Chapter classes
  * **What is a chapter?** A chapter is a segment of a book that contains sequence of events laid out by the author.
  * The Chapter interface has no constructor, one virtual destructor for memory management, and one implementable `virtual void` method called `read()`.
  * Chapter classes will implement the Chapter interface (Chapter01, Chapter02, ... Chapter14) and will store their respective plot segments in `read()`.

2. Book class
  * **What is a book?** A book is a collection of chapters compiled in a particular order by an author.
  * Represented as an array of chapters like so: `Chapter* mChapters[14]`
  * All 14 of TTM's chapters are initialized in a polymorphic fashion in the Book class' constructor.
  * When the Book's `startReading()` method is called, a for-each loop iterates through all the Chapters and calls each one's `read()` method.

### Defining Chronological Events and Time Travel
1. Events
  * **What is an event?** An event is an occurrence that occurs at a particular year. In essence, an event can contain a year, location, a set of characters, and a set of objects.
  * "Event" is a user-defined type. It's just a `void` callback with the following parameters: `unsigned int year`, `std::string location`, `Character* globalChars[]`, and `Object* objects[]`.
  * Events execute only after the current Chapter's `read()` has finished executing.
  * Characters or Objects that are "ephemeral" (that is, introduced and forgotten/destroyed in the same Event or Chapter) simply go out of scope when the Event/Chapter is done executing.

2. Timeline class
  * **What is a timeline?** A timeline is a construct that stores an ordered list of events sorted in chronological order, in effect keeping track of the past, present, and future. It must be sorted by year in ascending order at all times.
  * A Timeline class contains two things: an `std::vector<Event*>` ordered by year, and a `unsigned int` counter representing the current year. Since TTM never bothers to travel into BC times, we'll assume an always positive year count.
  * Every time an Event* is inserted into or removed from the `vector`, the Timeline is sorted using a merge sort algorithm. Since TTM is a book about time travel, the Timeline must be able to accept anachronistic Events, order them, and maintain chronological integrity over time.
  * Chapter classes' `read()` methods submit events to the Timeline. These events aren't necessarily in chronological order.
  * A book class must contain only one timeline. Having multiple timelines to manage at the same time is asking for trouble!

3. Time travel
  * **What is time travel?** This is very difficult to define, since the submission of events between chapters is already anachronistic in nature. Still, I define it as the manual adjustment of the timeline's year counter by a person or object from within an event without tampering with the timeline's natural order.
  * A particular TimeMachine object hooks into the timeline class and has the methods `getYear()`, `getLocation()`, `getCharacters()`, `getPilot()`, and `getObjects()` which retrive event data according to the current year. The `travel(unsigned int year)` method is used to modify the current year.
  * Once the timeline's year counter has been adjusted, the aforementioned "get...()" methods will grant the traveler to interact with the world around him.

### Example Execution Flow
* At the beginning of the story (`main.cpp`), the Timeline's year counter is set to 1895.
* Two Events are created from within a Chapter01 object like so:
``` cpp
Event victorianEngland(1895, "Richmond", vicCharacters, vicObjects) { ... }
Event futureEarth(802701, "Eloi Community", futCharacters, futObjects) { ... }
```
* The array `vicCharacters` contains the protagonist, and `vicObjects` contains a TimeMachine object "tmachine". Similarly, `futCharacters` contains several Eloi and Morlocks, and `futObjects` contains an Eloi dwelling and a forest.
* `victorianEngland` is submitted to the Timeline with its appropriate parameters and executed.
* From within `victorianEngland`, the TimeMachine object has its pilot property set to the protagonist. `tmachine.travel(802701)` is invoked, which modifies the Timeline's year counter from 1895 to 802701.
* Now, from within the `victorianEngland` Event, we can access elements of `futureEarth` by using the `tmachine.get...()` family of methods. Our protagonist has just traveled through time, simultaneously able to interact with the future and past, yet still tied to his original time frame. This is consistent with real-world paradoxes like "how does a time traveler age?"

### Unsolved Caveats
1. What happens when `tmachine.travel()` is invoked when there are multiple Events that occur on the same date?
2. Will the TimeMachine object allow Events to be modified or only read?
3. Will it ever be necessary to read data from Events that don't exist yet in the Timeline? If so, can this be worked around?
