#include <Triangle.h>
#include <sstream>
#include <cmath>

std::string triangle::toString() const{
	std::stringstream ss;
	for(int i = 0; i < 3; i++){
		ss << points[i].toString() << " ";
	}
	return ss.str() + "\n" + circleCenter.toString() + "\n" + std::to_string(circleRadius);
}

void triangle::setCircle() {
	std::array<std::array<float, 3>, 3> coefficients;
	std::array<float, 3> constants;

	// Prepare equation system
	for(int i=0; i<3; i++){
		vec2 vertex = points[i];
		coefficients[i][0] = 2 * vertex.x;
		coefficients[i][1] = 2 * vertex.y;
		coefficients[i][2] = -1.0f;
		constants[i] = vertex.x * vertex.x + vertex.y * vertex.y;
	}

	// transform left matrix to an upper triangular matrix
	for(int i=0; i<3; i++){
        // divide all values of the first row by the first non-zero element
        if(std::abs(coefficients[i][i]) < _EPSILON){
            continue;
        }
        constants[i] /= coefficients[i][i];
        for(int j=2; j>=i; j--){
            coefficients[i][j] /= coefficients[i][i];
        }


        // subtract all next rows by a multiplication of the first row
        // till all their first non-zero elements are zeros
        for(int j=i+1; j<3; j++){
            constants[j] -= coefficients[j][i] * constants[i];
            for(int k=2; k>=i; k--){
                coefficients[j][k] -= coefficients[j][i] * coefficients[i][k];
            }
        }
	}

	// transform the left matrix to a diagonal matrix
    for(int i=2; i>=0; i--){
        for(int j=i-1; j>=0; j--){
            constants[j] -= coefficients[j][i] * constants[i];
            coefficients[j][i] = 0.0f;
        }
    }

	circleCenter = vec2(constants[0], constants[1]);
	circleRadius = pow(circleCenter.x - points[0].x, 2);
	circleRadius += pow(circleCenter.y - points[0].y, 2);
	circleRadius = sqrt(circleRadius);
}