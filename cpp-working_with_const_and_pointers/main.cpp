#include <iostream>

void reset_scores(int *high_score, int *low_score);

int main() {
	int high_score {};
	int low_score {};

	reset_scores(&high_score, &low_score);

	// Pointer to constant
	const int *score_ptr_1 { &high_score };
	//*score_ptr_1 = 86; // Error
	score_ptr_1 = &low_score; // OK
	std::cout << "Score (pointer to constant after) stuff: " << *score_ptr_1 << std::endl;

	reset_scores(&high_score, &low_score);

	// Constant pointer
	int *const score_ptr_2 { &high_score };
        *score_ptr_2 = 86; // OK
        //score_ptr_2 = &low_score; // Error
        std::cout << "Score (constant pointer) after stuff: " << *score_ptr_2 << std::endl;

	reset_scores(&high_score, &low_score);

	// Constant pointer to constant
        const int *const score_ptr_3 { &high_score };
        //*score_ptr_3 = 86; // Error
        //score_ptr_3 = &low_score; // Error
        std::cout << "Score (constant pointer to constant) after stuff: " << *score_ptr_3 << std::endl;

}

void reset_scores(int *high_score, int *low_score) {
	*high_score = 100;
	*low_score = 65;
}
