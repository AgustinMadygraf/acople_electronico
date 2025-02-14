#ifndef IPIDSTRATEGY_H
#define IPIDSTRATEGY_H

class IPIDStrategy {
public:
    virtual ~IPIDStrategy() {}
    virtual int compute(float setpoint, float measurement) = 0;
};

#endif // IPIDSTRATEGY_H
