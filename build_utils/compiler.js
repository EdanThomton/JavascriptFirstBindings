export async function gcc_compile_for_roborio(path, filename, outpath, outname) {

    const file_hash = new Bun.CryptoHasher("sha256");
    file_hash.update(filename);

    try {
        const comp_directives = 
        /* OPTIONS */
        `/Users/et27076/wpilib/2025/roborio/bin/arm-frc2025-linux-gnueabi-g++ -o "${outpath}/objects/${outname}.o" ` +
        "-x c++ -c -fPIC -pthread -std=c++20 -nostdinc " + 

        /* HEADERS */
        "-I /Users/et27076/Downloads/node-v22.14.0-linux-armv7l/include/node " +
        "-I /Users/et27076/.gradle/caches/8.11/transforms/608ed045dff1c2fc0a47e0dfa557a81a/transformed/REVLib-cpp-2025.0.3-headers " + 
        "-I /Users/et27076/.gradle/caches/8.11/transforms/a6b7829cc29fc50eb925c726fbb45259/transformed/REVLib-driver-2025.0.3-headers " + 
        "-I /Users/et27076/.gradle/caches/8.11/transforms/2a52b37915468ab92a32d06c8a36092c/transformed/wpilibNewCommands-cpp-2025.1.1-headers " +
        "-I /Users/et27076/.gradle/caches/8.11/transforms/905890a9ecc7aae2df3c41f534caed02/transformed/wpilibc-cpp-2025.1.1-headers " +
        "-I /Users/et27076/.gradle/caches/8.11/transforms/30be1409dc8bd5d5529a7008f22120a0/transformed/ntcore-cpp-2025.1.1-headers " +
        "-I /Users/et27076/.gradle/caches/8.11/transforms/fa5f891ca047fdf27f454a0be8fc4bba/transformed/hal-cpp-2025.1.1-headers " +
        "-I /Users/et27076/.gradle/caches/8.11/transforms/b8870bf9de8015e3bb7f43008f6f7baa/transformed/wpimath-cpp-2025.1.1-headers " +
        "-I /Users/et27076/.gradle/caches/8.11/transforms/5b43fafba6766bf9d8c2a372814148c7/transformed/wpinet-cpp-2025.1.1-headers " +
        "-I /Users/et27076/.gradle/caches/8.11/transforms/2de9ffc4e1c039ae757cb320d9ada4bd/transformed/wpiutil-cpp-2025.1.1-headers " +
        "-I /Users/et27076/.gradle/caches/8.11/transforms/1728f564a9219ac405553f6696b6521c/transformed/netcomm-2025.2.0-headers " +
        "-I /Users/et27076/.gradle/caches/8.11/transforms/7647cda76e09e087ad726689ad375b30/transformed/chipobject-2025.2.0-headers " +
        "-I /Users/et27076/.gradle/caches/8.11/transforms/4d7811f74a7841ded4540754927c4d9f/transformed/visa-2025.2.0-headers " +
        "-I /Users/et27076/.gradle/caches/8.11/transforms/7413a25d0e87cf1e6ce053b2931a0c62/transformed/cameraserver-cpp-2025.1.1-headers " +
        "-I /Users/et27076/.gradle/caches/8.11/transforms/a6c40686e228f9ff3262b264c91fc310/transformed/cscore-cpp-2025.1.1-headers " +
        "-I /Users/et27076/.gradle/caches/8.11/transforms/48f2a7eb6f51f19375bfc634ebd40e62/transformed/apriltag-cpp-2025.1.1-headers " +
        "-I /Users/et27076/.gradle/caches/8.11/transforms/99276f9db0161a35fb238e22236e2f3d/transformed/opencv-cpp-4.10.0-3-headers " +

        /* SYSTEM HEADERS */
        "-isystem /Users/et27076/wpilib/2025/roborio/arm-nilrt-linux-gnueabi/sysroot/usr/lib/gcc/arm-nilrt-linux-gnueabi/12/include " +
        "-isystem /Users/et27076/wpilib/2025/roborio/arm-nilrt-linux-gnueabi/sysroot/usr/lib/gcc/arm-nilrt-linux-gnueabi/12/include-fixed " +
        "-isystem /Users/et27076/wpilib/2025/roborio/arm-nilrt-linux-gnueabi/sysroot/usr/include/c++/12 " +
        "-isystem /Users/et27076/wpilib/2025/roborio/arm-nilrt-linux-gnueabi/sysroot/usr/include/c++/12/arm-nilrt-linux-gnueabi " +
        "-isystem /Users/et27076/wpilib/2025/roborio/arm-nilrt-linux-gnueabi/sysroot/usr/include/c++/12/backward " +
        "-isystem /Users/et27076/wpilib/2025/roborio/arm-nilrt-linux-gnueabi/sysroot/usr/include " +

        /* FILE TO COMPILE */
        `"${path}/${filename}"`;

        const link_directives = 
        `/Users/et27076/wpilib/2025/roborio/bin/arm-frc2025-linux-gnueabi-g++ -o "${outpath}/${outname}.node" ` +
        "-shared -ldl -latomic -pthread " +
        "/Users/et27076/.gradle/caches/8.11/transforms/730b16826ec15e633b786af24d8b6157/transformed/wpilibNewCommands-cpp-2025.1.1-linuxathena/linux/athena/shared/libwpilibNewCommands.so " +
        "/Users/et27076/.gradle/caches/8.11/transforms/c7e12e8084df6aadb8c98aa877007256/transformed/REVLib-cpp-2025.0.3-linuxathenastatic/linux/athena/static/libREVLib.a " +
        "/Users/et27076/.gradle/caches/8.11/transforms/1ca53b6ff6dc6c976ec8fa742969cd0f/transformed/REVLib-driver-2025.0.3-linuxathenastatic/linux/athena/static/libREVLibDriver.a " +
        "/Users/et27076/.gradle/caches/8.11/transforms/295c6cd76a4bb87d74796d8fa91c8748/transformed/wpilibc-cpp-2025.1.1-linuxathena/linux/athena/shared/libwpilibc.so " +
        "/Users/et27076/.gradle/caches/8.11/transforms/e55d25aa82fe3a3a3b26edfbf544b330/transformed/ntcore-cpp-2025.1.1-linuxathena/linux/athena/shared/libntcore.so " +
        "/Users/et27076/.gradle/caches/8.11/transforms/b930ea114e782c5e2aee667caebd77e2/transformed/hal-cpp-2025.1.1-linuxathena/linux/athena/shared/libwpiHal.so " +
        "/Users/et27076/.gradle/caches/8.11/transforms/01cd726b6e5ec6e7aeea6e11836a8201/transformed/wpimath-cpp-2025.1.1-linuxathena/linux/athena/shared/libwpimath.so " +
        "/Users/et27076/.gradle/caches/8.11/transforms/e746fc1c483a40ec43796d7341fcf8d9/transformed/wpinet-cpp-2025.1.1-linuxathena/linux/athena/shared/libwpinet.so " +
        "/Users/et27076/.gradle/caches/8.11/transforms/8440317f709ebf8adc7a78b2e4b53c94/transformed/wpiutil-cpp-2025.1.1-linuxathena/linux/athena/shared/libwpiutil.so " +
        "/Users/et27076/.gradle/caches/8.11/transforms/77650368b17da567ae8080d39ba877e6/transformed/netcomm-2025.2.0-linuxathena/linux/athena/shared/libFRC_NetworkCommunication.so.25.0.0 " +
        "/Users/et27076/.gradle/caches/8.11/transforms/045b5eeb7eb10e26bb81cb923554d43b/transformed/chipobject-2025.2.0-linuxathena/linux/athena/shared/libRoboRIO_FRC_ChipObject.so.25.0.0 " +
        "/Users/et27076/.gradle/caches/8.11/transforms/61fcd225eee1505367f744d3f9a000a7/transformed/visa-2025.2.0-linuxathena/linux/athena/shared/libvisa.so.23.3.0 " +
        "/Users/et27076/.gradle/caches/8.11/transforms/b8f6b6e26a4a033b17c6ce8ca3078dd1/transformed/runtime-2025.2.0-linuxathena/linux/athena/shared/libfpgalvshim.so " +
        "/Users/et27076/.gradle/caches/8.11/transforms/b8f6b6e26a4a033b17c6ce8ca3078dd1/transformed/runtime-2025.2.0-linuxathena/linux/athena/shared/libembcanshim.so " +
        "/Users/et27076/.gradle/caches/8.11/transforms/7119445099d961762314fae78902741e/transformed/cameraserver-cpp-2025.1.1-linuxathena/linux/athena/shared/libcameraserver.so " +
        "/Users/et27076/.gradle/caches/8.11/transforms/83c48c467013131ef75b99d433e4d7fb/transformed/cscore-cpp-2025.1.1-linuxathena/linux/athena/shared/libcscore.so " +
        "/Users/et27076/.gradle/caches/8.11/transforms/63e41c6ee75bcc4a9deef9abbc907095/transformed/apriltag-cpp-2025.1.1-linuxathena/linux/athena/shared/libapriltag.so " +
        "/Users/et27076/.gradle/caches/8.11/transforms/76a0e5adf017f878add44c44ce155ca1/transformed/opencv-cpp-4.10.0-3-linuxathena/linux/athena/shared/libopencv_photo.so.4.10 " +
        "/Users/et27076/.gradle/caches/8.11/transforms/76a0e5adf017f878add44c44ce155ca1/transformed/opencv-cpp-4.10.0-3-linuxathena/linux/athena/shared/libopencv_video.so.4.10 " +
        "/Users/et27076/.gradle/caches/8.11/transforms/76a0e5adf017f878add44c44ce155ca1/transformed/opencv-cpp-4.10.0-3-linuxathena/linux/athena/shared/libopencv_features2d.so.4.10 " +
        "/Users/et27076/.gradle/caches/8.11/transforms/76a0e5adf017f878add44c44ce155ca1/transformed/opencv-cpp-4.10.0-3-linuxathena/linux/athena/shared/libopencv_objdetect.so.4.10 " +
        "/Users/et27076/.gradle/caches/8.11/transforms/76a0e5adf017f878add44c44ce155ca1/transformed/opencv-cpp-4.10.0-3-linuxathena/linux/athena/shared/libopencv_imgcodecs.so.4.10 " +
        "/Users/et27076/.gradle/caches/8.11/transforms/76a0e5adf017f878add44c44ce155ca1/transformed/opencv-cpp-4.10.0-3-linuxathena/linux/athena/shared/libopencv_aruco.so.4.10 " +
        "/Users/et27076/.gradle/caches/8.11/transforms/76a0e5adf017f878add44c44ce155ca1/transformed/opencv-cpp-4.10.0-3-linuxathena/linux/athena/shared/libopencv_flann.so.4.10 " +
        "/Users/et27076/.gradle/caches/8.11/transforms/76a0e5adf017f878add44c44ce155ca1/transformed/opencv-cpp-4.10.0-3-linuxathena/linux/athena/shared/libopencv_videoio.so.4.10 " +
        "/Users/et27076/.gradle/caches/8.11/transforms/76a0e5adf017f878add44c44ce155ca1/transformed/opencv-cpp-4.10.0-3-linuxathena/linux/athena/shared/libopencv_stitching.so.4.10 " +
        "/Users/et27076/.gradle/caches/8.11/transforms/76a0e5adf017f878add44c44ce155ca1/transformed/opencv-cpp-4.10.0-3-linuxathena/linux/athena/shared/libopencv_ml.so.4.10 " +
        "/Users/et27076/.gradle/caches/8.11/transforms/76a0e5adf017f878add44c44ce155ca1/transformed/opencv-cpp-4.10.0-3-linuxathena/linux/athena/shared/libopencv_calib3d.so.4.10 " +
        "/Users/et27076/.gradle/caches/8.11/transforms/76a0e5adf017f878add44c44ce155ca1/transformed/opencv-cpp-4.10.0-3-linuxathena/linux/athena/shared/libopencv_highgui.so.4.10 " +
        "/Users/et27076/.gradle/caches/8.11/transforms/76a0e5adf017f878add44c44ce155ca1/transformed/opencv-cpp-4.10.0-3-linuxathena/linux/athena/shared/libopencv_core.so.4.10 " +
        "/Users/et27076/.gradle/caches/8.11/transforms/76a0e5adf017f878add44c44ce155ca1/transformed/opencv-cpp-4.10.0-3-linuxathena/linux/athena/shared/libopencv_dnn.so.4.10 " +
        "/Users/et27076/.gradle/caches/8.11/transforms/76a0e5adf017f878add44c44ce155ca1/transformed/opencv-cpp-4.10.0-3-linuxathena/linux/athena/shared/libopencv_gapi.so.4.10 " +
        "/Users/et27076/.gradle/caches/8.11/transforms/76a0e5adf017f878add44c44ce155ca1/transformed/opencv-cpp-4.10.0-3-linuxathena/linux/athena/shared/libopencv_imgproc.so.4.10 " +
        `"${outpath}/objects/${outname}.o"`

        await Bun.$`${{raw:comp_directives}}`.text()
        await Bun.$`${{raw:link_directives}}`.text()

        return 1;
    } catch(e) {
        let comp_output = Bun.file(`${outpath}/ERROR_LOG_${outname}.txt`);
        Bun.write(comp_output, e.stderr);
        console.error(e.stderr.toString());

        return -1;
    }
}