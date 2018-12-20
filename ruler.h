#ifndef _RULER_H__
#define _RULER_H__
#define AVG 9
class ruler 
{
    
    public:
    int TrigPin= 27;
    int EchoPin =26;
    long TimeOut=50000;
    public:
    ruler();
    void init();
    void init(int e, int t);
    void init(int e, int t, int timeout);
    int mm();
    int mm_avg();
};
#endif
