//
// Created by 罗瑞笛 on 2023/9/25.
//

#ifndef CHAPTER7_EIGEN_TEST_H
#define CHAPTER7_EIGEN_TEST_H

#include "Eigen/Core"
#include "Eigen/Geometry"

void eigen_rotate(){

    Eigen::Matrix3d rotation_matrix =  Eigen::Matrix3d::Identity();
    // This class is not aimed to be used to store a rotation transformation,
    // but rather to make easier the creation of other rotation (Quaternion, rotation Matrix)
    // and transformation objects.

    // 角轴 -> Matrix
    Eigen::AngleAxisd rotation_vector(M_PI / 4, Eigen::Vector3d(0, 0, 1));     //沿 Z 轴旋转 45 度
    //Eigen::AngleAxis rotation_vector(M_PI/4 ,Eigen::Vector3d(0,0,1));
    std::cout.precision(3);
    std::cout << " Rotat vec -> Matrix \n"  << rotation_vector.matrix() << std::endl;
    Eigen::Vector3d v(1,0,0);
    Eigen::Vector3d v_roated45 =  rotation_vector * v;
    std::cout << v_roated45 << std::endl;
    rotation_matrix = rotation_vector.toRotationMatrix(); // 与 rotation_vector.matrix()  效果一致
    std::cout << " Rotat vec -> Matrix 2 \n"  << rotation_matrix << std::endl;

    // 角轴 -> euler角
    Eigen::Vector3d  eulaer_angle = rotation_matrix.eulerAngles(2,1,0); // 【矩阵被分解】 矩阵分解为先绕 z(2) -> y(1) -> x(0)
    std::cout << "Matrix -> eulaer Angle \n" <<  eulaer_angle << std::endl;


    // Transform 矩阵（4x4） 等距变换是一种保持距离和角度不变的变换 ---> Isometry
    // pre = 左乘
    Eigen::Isometry3d  T = Eigen::Isometry3d::Identity();
    T.rotate(rotation_vector);
    T.pretranslate(Eigen::Vector3d(1,3,4)); // 用一个向量表示位移[左乘 Applies on the left ]
    std::cout << T.matrix() << std::endl;

    // tran = 右乘
    Eigen::Isometry3d  T2 = Eigen::Isometry3d::Identity();
    T2.rotate(rotation_vector);
    T2.translate(Eigen::Vector3d(1,3,4)); //用一个向量表示位移[右乘  Applies on the right]
    std::cout << T2.matrix() << std::endl;

    Eigen::Vector3d preMoved = T*v;
    std::cout << preMoved << std::endl;
    Eigen::Vector3d afterMove = T2*v;
    std::cout << afterMove << std::endl;

}



#endif //CHAPTER7_EIGEN_TEST_H
