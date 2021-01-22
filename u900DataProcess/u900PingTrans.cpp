#include <u900DataProcess/u900PingTrans.h>
u900PingTrans::u900PingTrans(){

}

u900PingTrans::~u900PingTrans(){

}

void u900PingTrans::u900PingTransInit(){
    channelNum = 2;
}

int u900PingTrans::u900PingToXtfStruct(char *xtfStream){ 
    long int curNum = 0;

    //FileHeader
    xtfStructData.fileheader.FileFormat = xtfStream[curNum];
    curNum++;
    xtfStructData.fileheader.SystemType = xtfStream[curNum];
    curNum++;
    for(int i = 0; i < 8; i++){
        xtfStructData.fileheader.RecordingProgramName[i] = xtfStream[curNum + i];
    }
    curNum += 8;
    for(int i = 0; i < 8; i++){
        xtfStructData.fileheader.RecordingProgramVersion[i] = xtfStream[curNum + i];
    }
    curNum += 8;
    for(int i = 0; i < 16; i++){
        xtfStructData.fileheader.SonarName[i] = xtfStream[curNum + i];
    }
    curNum += 16;
    get_binary_short(true, &xtfStream[curNum], &(xtfStructData.fileheader.SonarType));
    curNum += 2;
    for(int i = 0; i < 64; i++){
        xtfStructData.fileheader.NoteString[i] = xtfStream[curNum + i];
    }
    curNum += 64;
    for(int i = 0; i < 64; i++){
        xtfStructData.fileheader.ThisFileName[i] = xtfStream[curNum + i];
    }
    curNum += 64;
    get_binary_short(true, &xtfStream[curNum], &(xtfStructData.fileheader.SonarType));
    curNum += 2;
    get_binary_short(true, &xtfStream[curNum], &(xtfStructData.fileheader.NumberOfSonarChannels));
    curNum += 2;
    get_binary_short(true, &xtfStream[curNum], &(xtfStructData.fileheader.NumberOfBathymetryChannels));
    curNum += 2;
    get_binary_short(true, &xtfStream[curNum], &(xtfStructData.fileheader.Reserved1));
    curNum += 2;
    get_binary_short(true, &xtfStream[curNum], &(xtfStructData.fileheader.Reserved2));
    curNum += 2;
    get_binary_short(true, &xtfStream[curNum], &(xtfStructData.fileheader.Reserved3));
    curNum += 2;
    get_binary_short(true, &xtfStream[curNum], &(xtfStructData.fileheader.Reserved4));
    curNum += 2;
    get_binary_short(true, &xtfStream[curNum], &(xtfStructData.fileheader.Reserved5));
    curNum += 2;
    get_binary_short(true, &xtfStream[curNum], &(xtfStructData.fileheader.Reserved6));
    curNum += 2;
    //get_binary_float(true, &xtfStream[curNum], &(xtfStructData.fileheader.ReferencePointHeight));
    //curNum += 4;
    for(int i = 0; i < 12; i++){
        xtfStructData.fileheader.ProjectionType[i] = xtfStream[curNum + i];
    }
    curNum += 12;
    for(int i = 0; i < 10; i++){
        xtfStructData.fileheader.SpheroidType[i] = xtfStream[curNum + i];
    }
    curNum += 10;
    get_binary_int(true, &xtfStream[curNum], (int *)&(xtfStructData.fileheader.NavigationLatency));
    curNum += 4;
    get_binary_float(true, &xtfStream[curNum], &(xtfStructData.fileheader.OriginY));
    curNum += 4;
    get_binary_float(true, &xtfStream[curNum], &(xtfStructData.fileheader.OriginX));
    curNum += 4;
    get_binary_float(true, &xtfStream[curNum], &(xtfStructData.fileheader.NavOffsetY));
    curNum += 4;
    get_binary_float(true, &xtfStream[curNum], &(xtfStructData.fileheader.NavOffsetX));
    curNum += 4;
    get_binary_float(true, &xtfStream[curNum], &(xtfStructData.fileheader.NavOffsetZ));
    curNum += 4;
    get_binary_float(true, &xtfStream[curNum], &(xtfStructData.fileheader.NavOffsetYaw));
    curNum += 4;
    get_binary_float(true, &xtfStream[curNum], &(xtfStructData.fileheader.MRUOffsetY));
    curNum += 4;
    get_binary_float(true, &xtfStream[curNum], &(xtfStructData.fileheader.MRUOffsetX));
    curNum += 4;
    get_binary_float(true, &xtfStream[curNum], &(xtfStructData.fileheader.MRUOffsetZ));
    curNum += 4;
    get_binary_float(true, &xtfStream[curNum], &(xtfStructData.fileheader.MRUOffsetYaw));
    curNum += 4;
    get_binary_float(true, &xtfStream[curNum], &(xtfStructData.fileheader.MRUOffsetPitch));
    curNum += 4;
    get_binary_float(true, &xtfStream[curNum], &(xtfStructData.fileheader.MRUOffsetRoll));
    curNum += 4;

    //XtfFileHeader.ChanInfo
    channelNum = xtfStructData.fileheader.NumberOfSonarChannels;
    for(int curChannelNum = 0; curChannelNum < channelNum; curChannelNum++){
        xtfStructData.fileheader.chaninfo[curChannelNum].TypeOfChannel = xtfStream[curNum];
        curNum++;
        xtfStructData.fileheader.chaninfo[curChannelNum].SubChannelNumber = xtfStream[curNum];
        curNum++;
        get_binary_short(true, &xtfStream[curNum], (short int *)&(xtfStructData.fileheader.chaninfo[curChannelNum].CorrectionFlags));
        curNum += 2;
        get_binary_short(true, &xtfStream[curNum], (short int *)&(xtfStructData.fileheader.chaninfo[curChannelNum].UniPolar));
        curNum += 2;
        get_binary_short(true, &xtfStream[curNum], (short int *)&(xtfStructData.fileheader.chaninfo[curChannelNum].BytesPerSample));
        curNum += 2;
        get_binary_int(true, &xtfStream[curNum], (int *)&(xtfStructData.fileheader.chaninfo[curChannelNum].SamplesPerChannel));
        curNum += 4;
        for (int i = 0; i < 16; i++){
            xtfStructData.fileheader.chaninfo[curChannelNum].ChannelName[i] = xtfStream[curNum + i];
        }
        curNum += 16;
        get_binary_float(true, &xtfStream[curNum], &(xtfStructData.fileheader.chaninfo[curChannelNum].VoltScale));
        curNum += 4;
        get_binary_float(true, &xtfStream[curNum], &(xtfStructData.fileheader.chaninfo[curChannelNum].Frequency));
        curNum += 4;
        get_binary_float(true, &xtfStream[curNum], &(xtfStructData.fileheader.chaninfo[curChannelNum].HorizBeamAngle));
        curNum += 4;
        get_binary_float(true, &xtfStream[curNum], &(xtfStructData.fileheader.chaninfo[curChannelNum].TiltAngle));
        curNum += 4;
        get_binary_float(true, &xtfStream[curNum], &(xtfStructData.fileheader.chaninfo[curChannelNum].BeamWidth));
        curNum += 4;
        get_binary_float(true, &xtfStream[curNum], &(xtfStructData.fileheader.chaninfo[curChannelNum].OffsetX));
        curNum += 4;
        get_binary_float(true, &xtfStream[curNum], &(xtfStructData.fileheader.chaninfo[curChannelNum].OffsetY));
        curNum += 4;
        get_binary_float(true, &xtfStream[curNum], &(xtfStructData.fileheader.chaninfo[curChannelNum].OffsetZ));
        curNum += 4;
        get_binary_float(true, &xtfStream[curNum], &(xtfStructData.fileheader.chaninfo[curChannelNum].OffsetYaw));
        curNum += 4;
        get_binary_float(true, &xtfStream[curNum], &(xtfStructData.fileheader.chaninfo[curChannelNum].OffsetPitch));
        curNum += 4;
        get_binary_float(true, &xtfStream[curNum], &(xtfStructData.fileheader.chaninfo[curChannelNum].OffsetRoll));
        curNum += 4;
        for (int i = 0; i < 56; i++){
            xtfStructData.fileheader.chaninfo[curChannelNum].ReservedArea[i] = xtfStream[curNum + i];
        }
        curNum += 56;
    }
    
    //Finish reading the xtfFileHeader, which length is 1024
    curNum = 1024;

    //pingHeader
    //pingHeader.packetHeader
    get_binary_short(true, &xtfStream[curNum], &(xtfStructData.pingheader.packetHeader.MagicNumber));
    curNum += 2;
    xtfStructData.pingheader.packetHeader.HeaderType = xtfStream[curNum];
    curNum++;
    xtfStructData.pingheader.packetHeader.SubChannelNumber = xtfStream[curNum];
    curNum++;
    get_binary_short(true, &xtfStream[curNum], (short int *)&(xtfStructData.pingheader.packetHeader.NumChansToFollow));
    curNum += 2;
    get_binary_short(true, &xtfStream[curNum], (short int *)&(xtfStructData.pingheader.packetHeader.Reserved1[0]));
    curNum += 2;
    get_binary_short(true, &xtfStream[curNum], (short int *)&(xtfStructData.pingheader.packetHeader.Reserved1[1]));
    curNum += 2;
    get_binary_int(true, &xtfStream[curNum], (int *)&(xtfStructData.pingheader.packetHeader.NumBytesThisRecord));
    curNum += 4;

    //pingHeader after packetHeader
    get_binary_short(true, &xtfStream[curNum], (short int *)&(xtfStructData.pingheader.Year));
    curNum += 2;
    xtfStructData.pingheader.Month = xtfStream[curNum];
    curNum++;
    xtfStructData.pingheader.Day = xtfStream[curNum];
    curNum++;
    xtfStructData.pingheader.Hour = xtfStream[curNum];
    curNum++;
    xtfStructData.pingheader.Minute = xtfStream[curNum];
    curNum++;
    xtfStructData.pingheader.Second = xtfStream[curNum];
    curNum++;
    xtfStructData.pingheader.HSeconds = xtfStream[curNum];
    curNum++;
    get_binary_short(true, &xtfStream[curNum], (short int *)&(xtfStructData.pingheader.JulianDay));
    curNum += 2;
    get_binary_short(true, &xtfStream[curNum], (short int *)&(xtfStructData.pingheader.CurrentLineID));
    curNum += 2;
    get_binary_short(true, &xtfStream[curNum], (short int *)&(xtfStructData.pingheader.EventNumber));
    curNum += 2;
    get_binary_int(true, &xtfStream[curNum], (int *)&(xtfStructData.pingheader.PingNumber));
    curNum += 4;
    get_binary_float(true, &xtfStream[curNum], &(xtfStructData.pingheader.SoundVelocity));
    curNum += 4;
    get_binary_float(true, &xtfStream[curNum], &(xtfStructData.pingheader.OceanTide));
    curNum += 4;
    get_binary_int(true, &xtfStream[curNum], (int *)&(xtfStructData.pingheader.Reserved2));
    curNum += 4;
    get_binary_float(true, &xtfStream[curNum], &(xtfStructData.pingheader.ConductivityFreq));
    curNum += 4;
    get_binary_float(true, &xtfStream[curNum], &(xtfStructData.pingheader.TemperatureFreq));
    curNum += 4;
    get_binary_float(true, &xtfStream[curNum], &(xtfStructData.pingheader.PressureFreq));
    curNum += 4;
    get_binary_float(true, &xtfStream[curNum], &(xtfStructData.pingheader.PressureTemp));
    curNum += 4;
    get_binary_float(true, &xtfStream[curNum], &(xtfStructData.pingheader.Conductivity));
    curNum += 4;
    get_binary_float(true, &xtfStream[curNum], &(xtfStructData.pingheader.WaterTemperature));
    curNum += 4;
    get_binary_float(true, &xtfStream[curNum], &(xtfStructData.pingheader.Pressure));
    curNum += 4;
    get_binary_float(true, &xtfStream[curNum], &(xtfStructData.pingheader.ComputedSoundVelocity));
    curNum += 4;
    get_binary_float(true, &xtfStream[curNum], &(xtfStructData.pingheader.MagX));
    curNum += 4;
    get_binary_float(true, &xtfStream[curNum], &(xtfStructData.pingheader.MagY));
    curNum += 4;
    get_binary_float(true, &xtfStream[curNum], &(xtfStructData.pingheader.MagZ));
    curNum += 4;
    get_binary_float(true, &xtfStream[curNum], &(xtfStructData.pingheader.AuxVal1));
    curNum += 4;
    get_binary_float(true, &xtfStream[curNum], &(xtfStructData.pingheader.AuxVal2));
    curNum += 4;
    get_binary_float(true, &xtfStream[curNum], &(xtfStructData.pingheader.AuxVal3));
    curNum += 4;
    get_binary_float(true, &xtfStream[curNum], &(xtfStructData.pingheader.AuxVal4));
    curNum += 4;
    get_binary_float(true, &xtfStream[curNum], &(xtfStructData.pingheader.AuxVal5));
    curNum += 4;
    get_binary_float(true, &xtfStream[curNum], &(xtfStructData.pingheader.AuxVal6));
    curNum += 4;
    get_binary_float(true, &xtfStream[curNum], &(xtfStructData.pingheader.SpeedLog));
    curNum += 4;
    get_binary_float(true, &xtfStream[curNum], &(xtfStructData.pingheader.Turbidity));
    curNum += 4;
    get_binary_float(true, &xtfStream[curNum], &(xtfStructData.pingheader.ShipSpeed));
    curNum += 4;
    get_binary_float(true, &xtfStream[curNum], &(xtfStructData.pingheader.ShipGyro));
    curNum += 4;
    get_binary_double(true, &xtfStream[curNum], &(xtfStructData.pingheader.ShipYcoordinate));
    curNum += 8;
    get_binary_double(true, &xtfStream[curNum], &(xtfStructData.pingheader.ShipXcoordinate));
    curNum += 8;
    get_binary_short(true, &xtfStream[curNum], (short int *)&(xtfStructData.pingheader.ShipAltitude));
    curNum += 2;
    get_binary_short(true, &xtfStream[curNum], (short int *)&(xtfStructData.pingheader.ShipDepth));
    curNum += 2;
    xtfStructData.pingheader.FixTimeHour = xtfStream[curNum];
    curNum++;
    xtfStructData.pingheader.FixTimeMinute = xtfStream[curNum];
    curNum++;
    xtfStructData.pingheader.FixTimeSecond = xtfStream[curNum];
    curNum++;
    xtfStructData.pingheader.FixTimeHSecond = xtfStream[curNum];
    curNum++;
    get_binary_float(true, &xtfStream[curNum], &(xtfStructData.pingheader.SensorSpeed));
    curNum += 4;
    get_binary_float(true, &xtfStream[curNum], &(xtfStructData.pingheader.KP));
    curNum += 4;
    get_binary_double(true, &xtfStream[curNum], &(xtfStructData.pingheader.SensorYcoordinate));
    curNum += 8;
    get_binary_double(true, &xtfStream[curNum], &(xtfStructData.pingheader.SensorXcoordinate));
    curNum += 8;
    get_binary_short(true, &xtfStream[curNum], (short int *)&(xtfStructData.pingheader.SonarStatus));
    curNum += 2;
    get_binary_short(true, &xtfStream[curNum], (short int *)&(xtfStructData.pingheader.RangeToFish));
    curNum += 2;
    get_binary_short(true, &xtfStream[curNum], (short int *)&(xtfStructData.pingheader.BearingToFish));
    curNum += 2;
    get_binary_short(true, &xtfStream[curNum], (short int *)&(xtfStructData.pingheader.CableOut));
    curNum += 2;
    get_binary_float(true, &xtfStream[curNum], &(xtfStructData.pingheader.Layback));
    curNum += 4;
    get_binary_float(true, &xtfStream[curNum], &(xtfStructData.pingheader.CableTension));
    curNum += 4;
    get_binary_float(true, &xtfStream[curNum], &(xtfStructData.pingheader.SensorDepth));
    curNum += 4;
    get_binary_float(true, &xtfStream[curNum], &(xtfStructData.pingheader.SensorPrimaryAltitude));
    curNum += 4;
    get_binary_float(true, &xtfStream[curNum], &(xtfStructData.pingheader.SensorAuxAltitude));
    curNum += 4;
    get_binary_float(true, &xtfStream[curNum], &(xtfStructData.pingheader.SensorPitch));
    curNum += 4;
    get_binary_float(true, &xtfStream[curNum], &(xtfStructData.pingheader.SensorRoll));
    curNum += 4;
    get_binary_float(true, &xtfStream[curNum], &(xtfStructData.pingheader.SensorHeading));
    curNum += 4;
    get_binary_float(true, &xtfStream[curNum], &(xtfStructData.pingheader.Heave));
    curNum += 4;
    get_binary_float(true, &xtfStream[curNum], &(xtfStructData.pingheader.Yaw));
    curNum += 4;
    get_binary_int(true, &xtfStream[curNum], (int *)&(xtfStructData.pingheader.AttitudeTimeTag));
    curNum += 4;
    get_binary_float(true, &xtfStream[curNum], &(xtfStructData.pingheader.DOT));
    curNum += 4;
    for(int i = 0; i < 24; i++){
        xtfStructData.pingheader.ReservedSpace[i] = xtfStream[curNum + i];
    }
    curNum += 24;

    //Finish reading the pingheader
    if((1024+256) != curNum){
        std::cout<<"Reading pingheader ERROR!!!"<<std::endl;
        return 1;
    }
    curNum = 1024 + 256;

    //XtfPingChanHeader 0th channel
    get_binary_short(true, &xtfStream[curNum], (short int *)&(xtfStructData.pingchanportheader.ChannelNumber));
    curNum += 2;
    get_binary_short(true, &xtfStream[curNum], (short int *)&(xtfStructData.pingchanportheader.DownsampleMethod));
    curNum += 2;
    get_binary_float(true, &xtfStream[curNum], &(xtfStructData.pingchanportheader.SlantRange));
    curNum += 4;
    get_binary_float(true, &xtfStream[curNum], &(xtfStructData.pingchanportheader.GroundRange));
    curNum += 4;
    get_binary_float(true, &xtfStream[curNum], &(xtfStructData.pingchanportheader.TimeDelay));
    curNum += 4;
    get_binary_float(true, &xtfStream[curNum], &(xtfStructData.pingchanportheader.TimeDuration));
    curNum += 4;
    get_binary_float(true, &xtfStream[curNum], &(xtfStructData.pingchanportheader.SecondsPerPing));
    curNum += 4;
    get_binary_short(true, &xtfStream[curNum], (short int *)&(xtfStructData.pingchanportheader.ProcessingFlags));
    curNum += 2;
    get_binary_short(true, &xtfStream[curNum], (short int *)&(xtfStructData.pingchanportheader.Frequency));
    curNum += 2;
    get_binary_short(true, &xtfStream[curNum], (short int *)&(xtfStructData.pingchanportheader.InitialGainCode));
    curNum += 2;
    get_binary_short(true, &xtfStream[curNum], (short int *)&(xtfStructData.pingchanportheader.GainCode));
    curNum += 2;
    get_binary_short(true, &xtfStream[curNum], (short int *)&(xtfStructData.pingchanportheader.BandWidth));
    curNum += 2;
    get_binary_int(true, &xtfStream[curNum], (int *)&(xtfStructData.pingchanportheader.ContactNumber));
    curNum += 4;
    get_binary_short(true, &xtfStream[curNum], (short int *)&(xtfStructData.pingchanportheader.ContactClassification));
    curNum += 2;
    xtfStructData.pingchanportheader.ContactSubNumber = xtfStream[curNum];
    curNum++;
    xtfStructData.pingchanportheader.ContactType = xtfStream[curNum];
    curNum++;
    get_binary_int(true, &xtfStream[curNum], (int *)&(xtfStructData.pingchanportheader.NumSamples));
    curNum += 4;
    get_binary_short(true, &xtfStream[curNum], (short int *)&(xtfStructData.pingchanportheader.Reserved));
    curNum += 2;
    get_binary_float(true, &xtfStream[curNum], &(xtfStructData.pingchanportheader.ContactTimeOffTrack));
    curNum += 4;
    xtfStructData.pingchanportheader.ContactCloseNumber = xtfStream[curNum];
    curNum++;
    xtfStructData.pingchanportheader.Reserved2 = xtfStream[curNum];
    curNum++;
    get_binary_float(true, &xtfStream[curNum], &(xtfStructData.pingchanportheader.FixedVSOP));
    curNum += 4;
    for(int i = 0; i < 6; i++){
        xtfStructData.pingchanportheader.ReservedSpace[i] = xtfStream[curNum + i];
    }
    curNum += 6;

    //port data 0th channel
    if(xtfStructData.fileheader.chaninfo[xtfStructData.pingchanportheader.ChannelNumber].BytesPerSample == 1){
        for(int i = 0; i < xtfStructData.pingchanportheader.NumSamples; i++){
            unsigned char *curPortNum = (unsigned char *)&xtfStream[curNum + i];
            xtfStructData.ssrawport[i] = (unsigned short )(*curPortNum);
            curNum++;
        }
    }
    else if(xtfStructData.fileheader.chaninfo[xtfStructData.pingchanportheader.ChannelNumber].BytesPerSample == 2){
        for(int i = 0; i < xtfStructData.pingchanportheader.NumSamples; i++){
            get_binary_short(true, &xtfStream[curNum], (short *)&(xtfStructData.ssrawport[i]));
            curNum += 2;
        }
    }
    else if(xtfStructData.fileheader.chaninfo[xtfStructData.pingchanportheader.ChannelNumber].BytesPerSample == 4){
        std::cout<<"Current software version can not support 32-bit data!!!"<<std::endl;
        return 2;
    }
    else{
        std::cout<<"Current software version only support 8-bit and 16-bit data!!!"<<std::endl;
        return 3;
    }

    ///XtfPingChanHeader 1st channel
    get_binary_short(true, &xtfStream[curNum], (short int *)&(xtfStructData.pingchanstbdheader.ChannelNumber));
    curNum += 2;
    get_binary_short(true, &xtfStream[curNum], (short int *)&(xtfStructData.pingchanstbdheader.DownsampleMethod));
    curNum += 2;
    get_binary_float(true, &xtfStream[curNum], &(xtfStructData.pingchanstbdheader.SlantRange));
    curNum += 4;
    get_binary_float(true, &xtfStream[curNum], &(xtfStructData.pingchanstbdheader.GroundRange));
    curNum += 4;
    get_binary_float(true, &xtfStream[curNum], &(xtfStructData.pingchanstbdheader.TimeDelay));
    curNum += 4;
    get_binary_float(true, &xtfStream[curNum], &(xtfStructData.pingchanstbdheader.TimeDuration));
    curNum += 4;
    get_binary_float(true, &xtfStream[curNum], &(xtfStructData.pingchanstbdheader.SecondsPerPing));
    curNum += 4;
    get_binary_short(true, &xtfStream[curNum], (short int *)&(xtfStructData.pingchanstbdheader.ProcessingFlags));
    curNum += 2;
    get_binary_short(true, &xtfStream[curNum], (short int *)&(xtfStructData.pingchanstbdheader.Frequency));
    curNum += 2;
    get_binary_short(true, &xtfStream[curNum], (short int *)&(xtfStructData.pingchanstbdheader.InitialGainCode));
    curNum += 2;
    get_binary_short(true, &xtfStream[curNum], (short int *)&(xtfStructData.pingchanstbdheader.GainCode));
    curNum += 2;
    get_binary_short(true, &xtfStream[curNum], (short int *)&(xtfStructData.pingchanstbdheader.BandWidth));
    curNum += 2;
    get_binary_int(true, &xtfStream[curNum], (int *)&(xtfStructData.pingchanstbdheader.ContactNumber));
    curNum += 4;
    get_binary_short(true, &xtfStream[curNum], (short int *)&(xtfStructData.pingchanstbdheader.ContactClassification));
    curNum += 2;
    xtfStructData.pingchanstbdheader.ContactSubNumber = xtfStream[curNum];
    curNum++;
    xtfStructData.pingchanstbdheader.ContactType = xtfStream[curNum];
    curNum++;
    get_binary_int(true, &xtfStream[curNum], (int *)&(xtfStructData.pingchanstbdheader.NumSamples));
    curNum += 4;
    get_binary_short(true, &xtfStream[curNum], (short int *)&(xtfStructData.pingchanstbdheader.Reserved));
    curNum += 2;
    get_binary_float(true, &xtfStream[curNum], &(xtfStructData.pingchanstbdheader.ContactTimeOffTrack));
    curNum += 4;
    xtfStructData.pingchanstbdheader.ContactCloseNumber = xtfStream[curNum];
    curNum++;
    xtfStructData.pingchanstbdheader.Reserved2 = xtfStream[curNum];
    curNum++;
    get_binary_float(true, &xtfStream[curNum], &(xtfStructData.pingchanstbdheader.FixedVSOP));
    curNum += 4;
    for(int i = 0; i < 6; i++){
        xtfStructData.pingchanstbdheader.ReservedSpace[i] = xtfStream[curNum + i];
    }
    curNum += 6;

    //port data 1st channel
    if(xtfStructData.fileheader.chaninfo[xtfStructData.pingchanstbdheader.ChannelNumber].BytesPerSample == 1){
        for(int i = 0; i < xtfStructData.pingchanstbdheader.NumSamples; i++){
            unsigned char *curPortNum = (unsigned char *)&xtfStream[curNum + i];
            xtfStructData.ssrawstbd[i] = (unsigned short )(*curPortNum);
            curNum++;
        }
    }
    else if(xtfStructData.fileheader.chaninfo[xtfStructData.pingchanstbdheader.ChannelNumber].BytesPerSample == 2){
        for(int i = 0; i < xtfStructData.pingchanstbdheader.NumSamples; i++){
            get_binary_short(true, &xtfStream[curNum], (short *)&(xtfStructData.ssrawstbd[i]));
            curNum += 2;
        }
    }
    else if(xtfStructData.fileheader.chaninfo[xtfStructData.pingchanstbdheader.ChannelNumber].BytesPerSample == 4){
        std::cout<<"Current software version can not support 32-bit data!!!"<<std::endl;
        return 2;
    }
    else{
        std::cout<<"Current software version only support 8-bit and 16-bit data!!!"<<std::endl;
        return 3;
    }   
    //std::cout<<"Y: "<<xtfStructData.pingheader.SensorYcoordinate<<std::endl;
    //std::cout<<"X: "<<xtfStructData.pingheader.SensorXcoordinate<<std::endl;
    //std::cout<<"X: "<<curNum<<std::endl;
    return 0;
}
