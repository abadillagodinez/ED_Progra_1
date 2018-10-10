#ifndef ANIMATIONSTRING_H
#define ANIMATIONSTRING_H
#include <iostream>
using namespace std;

class AnimationString
{
    string String;

    public:
    AnimationString();
    AnimationString(int);
    AnimationString(char);
    AnimationString(string);
    string getString();
};

#endif // ANIMATIONSTRING_H
