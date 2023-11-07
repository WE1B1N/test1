#include <stdio.h>
#include "hdf5.h"

int main() {
    hid_t file_id, dataset_id, dataspace_id;
    double data[10][500];

    // 打开HDF5文件
    file_id = H5Fopen("test1.h5", H5F_ACC_RDONLY, H5P_DEFAULT);

    // 打开数据集
    dataset_id = H5Dopen2(file_id, "dataset", H5P_DEFAULT);

    // 获取数据集的数据空间
    dataspace_id = H5Dget_space(dataset_id);

    // 读取数据
    H5Dread(dataset_id, H5T_NATIVE_DOUBLE, H5S_ALL, H5S_ALL, H5P_DEFAULT, data);

    // 输出读取的数据
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 500; j++) {
            printf("%f ", data[i][j]);
        }
        printf("\n");
    }

    // 关闭数据集、数据空间和文件
    H5Dclose(dataset_id);
    H5Sclose(dataspace_id);
    H5Fclose(file_id);

    return 0;
}
