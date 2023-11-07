#include <hdf5.h>

int main(){
    // hid_t是HDF5对象id通用数据类型，每个id标志一个HDF5对象
    hid_t file_id;
    // herr_t是HDF5报错和状态的通用数据类型
    herr_t status;
    // 文件id = H5Fcreate(const char *文件名,
    //                   unsigned 是否覆盖的flags,
    //                     - H5F_ACC_TRUNC->能覆盖
    //                     - H5F_ACC_EXCL->不能覆盖,报错
    //                   hid_t 建立性质,hid_t 访问性质);
    file_id = H5Fcreate("file.h5", H5F_ACC_TRUNC,
                         H5P_DEFAULT, H5P_DEFAULT);
    status = H5Fclose(file_id);

    // 打开刚建立的HDF文件并关闭
    // 文件id = H5Fopen(const char *文件名, 
    //                  unsigned 读写flags,
    //                    - H5F_ACC_RDWR可读写
    //                    - H5F_ACC_RDONLY只读 
    //                  hid_t 访问性质)
    hid_t file_open_id;
    file_id = H5Fopen("file.h5", H5F_ACC_RDWR, H5P_DEFAULT);
    status = H5Fclose(file_id);

    return 0;
}
