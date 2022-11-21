#ifndef __TASK__
#define __TASK__

/**
 * @brief Abstact class that defines a generic task.
 * 
 */
class Task
{
    public:
        /**
         * @brief Method used to call the task execution.
         * 
         */
        virtual void tick() = 0;
        /**
         * @brief Get the period of the task
         * 
         * @return unsigned long the periond of the task in milliseconds.
         */
        unsigned long getPeriod();
    protected:
        /**
         * @brief Initializes the period of the task.
         * 
         * @param period the period of the task in milliseconds.
         */
        void init(unsigned long period);
    private:
        unsigned long period;
};

#endif 