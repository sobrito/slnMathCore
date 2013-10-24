#include <model/MathResult.h>
#include <stdlib.h>

void mathResultAdd(struct MathResult *result, int operation, struct MathUnit*) {

}

void mathResultDel(struct MathResult *result) {

}

struct MathUnit *mathResultGet(struct MathResult *result, struct MathUnit *first, int *operation, struct MathUnit *second) {
    if (result == NULL) {
        return;
    }
    first = result->mathUnit;
    *operation = result->operation;
    second = result->mathResult == NULL ? NULL : result->mathResult->mathUnit;
}

void MathResultInit() {
    ApiMathResult.add = mathResultAdd;
    ApiMathResult.del = mathResultDel;
    ApiMathResult.get = mathResultGet;
}
