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
        void tick();
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
        /**
         * @brief Method that is called on the ticking of the task's period.
         */
        virtual void toExecute() = 0;
    private:
        unsigned long period;
        unsigned long lastExecuted = 0;
};

#endif 