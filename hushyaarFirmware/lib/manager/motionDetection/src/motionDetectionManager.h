#include <functional>
#include "../../lib/provider/pir/SR501/src/SR501Provider.h"

#define  HAS_MOVMENT_CALL_BACK_METHOD std::function<void()>

class MotionDetectionManager{
    private:
        SR501Provider _SR501Provider;
        HAS_MOVMENT_CALL_BACK_METHOD _onHasMovmentCallbackMethod;
    public:
        MotionDetectionManager();
        void setHasMovmentCallbackMethod(HAS_MOVMENT_CALL_BACK_METHOD onHasMovmentCallbackMethod);
        void Active();
        void Deactive();
        bool isActive();
};