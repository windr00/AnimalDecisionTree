
#include "conditional_binary_tree.h"
#include "conditions.h"
#include "results.h"


int main() {
    auto *root = new conditional_binary_tree();
    auto *warm_blood_branch = root->set_condition(CONDITION_IS_WARM_BLOODED)->create_yes_child(
                    CONDITION_NURSE_YOUNG)->get_yes_child()
            ->create_yes_child(RESULT_IS_MAMMAL)->create_no_child(RESULT_IS_BIRD);
    auto *cold_blood_branch = root->create_no_child(CONDITION_LAY_EGGS)->get_no_child()
            ->create_yes_child(RESULT_IS_REPTILES)->create_no_child(CONDITION_USE_GILLS);
    cold_blood_branch->get_no_child()->create_yes_child(RESULT_IS_FISH)->create_no_child(RESULT_IS_UNKNOWN);
    root->try_match_condition();
    return 0;

}