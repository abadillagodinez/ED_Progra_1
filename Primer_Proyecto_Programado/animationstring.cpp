#include "animationstring.h"

AnimationString::AnimationString(int n)
{
    String = std::to_string(n);
}
AnimationString::AnimationString(char c)
{
    String.push_back(c);
}
AnimationString::AnimationString(string ss)
{
    String = ss;
}
string AnimationString::getString()
{
    return String;
}
