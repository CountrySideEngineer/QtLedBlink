#ifndef CIOPING_H
#define CIOPING_H

class CIOPin
{
protected:
    CIOPin();
    virtual ~CIOPin();

public:
    /**
     * @brief getInstance
     * @return Singleton instance of CIOPin
     */
    static CIOPin& getInstance()
    {
        CIOPin::create();

        return *CIOPin::mInstance;
    }

    /**
     * @brief create
     *        Create instance of CIOPing class if it has not been created.
     */
    static void create()
    {
        if (nullptr == CIOPin::mInstance) {
            CIOPin::mInstance = new CIOPin();
        }
    }

    /**
     * @brief destroy
     *        Destory CIOPing singleton instance if it has been created.
     */
    static void destroy()
    {
        if (nullptr != CIOPin::mInstance) {
            delete CIOPin::mInstance;
            CIOPin::mInstance = nullptr;
        }
    }

protected:
    static CIOPin* mInstance;

};

#endif // CIOPING_H
