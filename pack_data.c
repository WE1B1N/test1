#include <stdio.h>
#include <stdlib.h>
#include "hdf5.h"

int main() {
    hid_t file_id, dataset_id, dataspace_id;
    hsize_t dims[2] = {4, 3};  // 数据维度
    float data[4][3] = {{1.1, 2.2, 3.3}, {4.4, 5.5, 6.6}, {7.7, 8.8, 9.9}, {10.0, 11.1, 12.2}};

    // 创建HDF5文件
    file_id = H5Fcreate("data.h5", H5F_ACC_TRUNC, H5P_DEFAULT, H5P_DEFAULT);

    // 创建数据空间
    dataspace_id = H5Screate_simple(2, dims, NULL);

    // 创建数据集
    dataset_id = H5Dcreate2(file_id, "/dataset", H5T_NATIVE_FLOAT, dataspace_id, H5P_DEFAULT, H5P_DEFAULT, H5P_DEFAULT);

    // 写入数据
    H5Dwrite(dataset_id, H5T_NATIVE_FLOAT, H5S_ALL, H5S_ALL, H5P_DEFAULT, data);

    // 关闭数据集、数据空间和文件
    H5Dclose(dataset_id);
    H5Sclose(dataspace_id);
    H5Fclose(file_id);

    return 0;
}
