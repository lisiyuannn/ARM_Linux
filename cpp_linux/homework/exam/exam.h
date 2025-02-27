#ifndef __EXAM_H
#define __EXAM_H

class Examinee
{
public:
    virtual ~Examinee();
    virtual void exam() = 0;
};

class ExcellentStd: public Examinee
{
public:
    virtual ~ExcellentStd();
    virtual void exam() override;
};

class PoorStd: public Examinee
{
private:
    ExcellentStd *gunner;
public:
    PoorStd();
    PoorStd(PoorStd &) = delete;
    PoorStd& operator=(PoorStd &) = delete;
    ~PoorStd();

    virtual void exam() override;
};

#endif
