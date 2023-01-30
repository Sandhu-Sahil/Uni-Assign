class Computer
{
    CPU CPUProcessor;
    public:
        Computer()
        {

        }
        Computer(const CPU cpu)
        {
            CPUProcessor = cpu;
        }
        void getCPU()
        {

        }
        void setCPU(CPU cpu)
        {
            CPUProcessor = cpu;
        }
};

class CPU
{
    double clock_speed;
    public:
        CPU()
        {

        }
        CPU(double a)
        {
            clock_speed = a;
        }
        void getClockSpeed()
        {

        }
        void SetClockSpeed(double a)
        {
            clock_speed = a;
        }
};

class PC :public Computer
{
    string PCname;
};