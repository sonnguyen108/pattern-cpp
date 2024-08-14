--- 
### Adapter Pattern

#### Use case
   - In many software situations it’s desirable to get feedback as soon as some
state change occurs: a new job is added to a task queue, a setting is changed
in some configuration object, a result is ready to be picked up, etc.
    - But at the same time, it would be highly undesirable to introduce explicit
dependencies between the subject (the observed entity that changes) and its
observers (the callbacks that are notified based on a state change)
    - On the contrary, the subject should be oblivious to the potentially many different
kinds of observers. And that’s for the simple reason that any direct
dependency would make the software harder to change and harder to
extend
    - This decoupling between the subject and its potentially many
observers is the intent of the Observer design pattern

### Things:
    Subject ---- (notify(/** smt))----> ObserverN( update(/** smt))

### Implement:
    1. Classic implementation
        - Use class inherit
        - Use template class (flexible type of Subject (loose couple ))
    2. Value Sematic implementaion
        - Passing update behavior (onUpdate) from outside of Observer
  
### Best practices:
    - 2 types:
      - pull observer: (stateless) use std::function() with single update() 
      - push observer: (statefull)
    - thread-safe
    - raw pointer
    - 
