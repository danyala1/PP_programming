import numpy as np

list_size = [100, 250, 500, 750, 1000, 1500, 2000, 2500]

for size in list_size:
    for e in range(1, 4):
        matrix_1 = np.loadtxt(f'matrix/matrix_1_2/m_1_{size}_{e}.txt')
        matrix_2 = np.loadtxt(f'matrix/matrix_1_2/m_2_{size}_{e}.txt')

        result_matrix = np.dot(matrix_1, matrix_2)

        expected_result = np.loadtxt(f'matrix/matrix_3/m_{size}_{e+1}.txt')

        is_equal = np.array_equal(result_matrix, expected_result)

        with open('file/check_py.txt', 'a', encoding='utf-8') as file:
            file.write(f"Размер матрицы: {result_matrix.shape}")
            file.write(" Результат совпал: " + str(is_equal) + '\n')
