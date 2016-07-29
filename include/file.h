#ifndef FILE_H
#define FILE_H

#include <3ds.h>
#include <string>

#define seek_beg 0
#define seek_cur 1
#define seek_end 2

class fsFile
{
    public:
        //One is for reading, the other is for writing
        fsFile(FS_Archive _arch, std::u16string _path, u32 openFlags);
        fsFile(FS_Archive _arch, std::u16string _path, u32 openFlags, u64 createSize);
        //Ascii
        fsFile(FS_Archive _arch, const char *_path, u32 openFlags);
        fsFile(FS_Archive _arch, const char *_path, u32 openFlags, u64 createSize);
        //Directly
        fsFile(FS_ArchiveID _arch, FS_Path archPath, FS_Path filePath, u32 openFlags);

        //returns if file is opened
        bool isOpened();

        //Reads to buff. Returns number of read bytes
        u32 read(u8 *buff, u32 max);
        //Same, only write
        u32 write(u8 *dat, u32 size);
        //gets next byte in file
        u8 getByte();
        //writes byte at offset
        void putByte(u8 put);

        void seek(int pos, u8 seekFrom);

        //Closes file
        bool close();

        //returns fileSize
        u64 size();
        u64 getOffset();

    private:
        Handle fileHandle;
        bool opened = false;
        FS_Archive arch;
        u64 fileSize, offset = 0;
};

#endif // FILE_H
