## Reference:
http://josuttis.com/download/meetingcpp/

## Youtube link:
https://www.youtube.com/watch?v=sACa3Ax7YB4&list=WL&index=4

1. For expensive members
- Initializing constructors take by value and move()
- Overload getters for && and const &

2. Moved from objects should not break invariants (Ideally in a valid but unsepcified state).

3. To disable move semantics =default other special members (like copy constructors and copy assigments).

4. Use noexcept when implementing special move members.