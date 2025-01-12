    function targMap = targDataMap(),

    ;%***********************
    ;% Create Parameter Map *
    ;%***********************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 9;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc paramMap
        ;%
        paramMap.nSections           = nTotSects;
        paramMap.sectIdxOffset       = sectIdxOffset;
            paramMap.sections(nTotSects) = dumSection; %prealloc
        paramMap.nTotData            = -1;

        ;%
        ;% Auto data (rtP)
        ;%
            section.nData     = 10;
            section.data(10)  = dumData; %prealloc

                    ;% rtP._CurrKi2f2Square_HFI_sldd_
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% rtP._CurrKpd2f2Square_HFI_sldd_
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% rtP._CurrKpq2f2Square_HFI_sldd_
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% rtP._PLL_Kd2f2Square_HFI_sldd_
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% rtP._PLL_Ki2f2Square_HFI_sldd_
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

                    ;% rtP._Pn2f2Square_HFI_sldd_
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 5;

                    ;% rtP._Rs2f2Square_HFI_sldd_
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 6;

                    ;% rtP._flux2f2Square_HFI_sldd_
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 7;

                    ;% rtP._spd_ki2f2Square_HFI_sldd_
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 8;

                    ;% rtP._spd_kp2f2Square_HFI_sldd_
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 9;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 7;
            section.data(7)  = dumData; %prealloc

                    ;% rtP.Int1_L
                    section.data(1).logicalSrcIdx = 10;
                    section.data(1).dtTransOffset = 0;

                    ;% rtP.Int1_Ts
                    section.data(2).logicalSrcIdx = 11;
                    section.data(2).dtTransOffset = 1;

                    ;% rtP.Int1_U
                    section.data(3).logicalSrcIdx = 12;
                    section.data(3).dtTransOffset = 2;

                    ;% rtP.InteriorPMSM_idq0
                    section.data(4).logicalSrcIdx = 13;
                    section.data(4).dtTransOffset = 3;

                    ;% rtP.InteriorPMSM_mechanical
                    section.data(5).logicalSrcIdx = 14;
                    section.data(5).dtTransOffset = 5;

                    ;% rtP.InteriorPMSM_omega_init
                    section.data(6).logicalSrcIdx = 15;
                    section.data(6).dtTransOffset = 8;

                    ;% rtP.InteriorPMSM_theta_init
                    section.data(7).logicalSrcIdx = 16;
                    section.data(7).dtTransOffset = 9;

            nTotData = nTotData + section.nData;
            paramMap.sections(2) = section;
            clear section

            section.nData     = 9;
            section.data(9)  = dumData; %prealloc

                    ;% rtP.PIDController3_InitialConditionForIntegrator
                    section.data(1).logicalSrcIdx = 17;
                    section.data(1).dtTransOffset = 0;

                    ;% rtP.PIDController2_InitialConditionForIntegrator
                    section.data(2).logicalSrcIdx = 18;
                    section.data(2).dtTransOffset = 1;

                    ;% rtP.InteriorPMSM_Ldq
                    section.data(3).logicalSrcIdx = 19;
                    section.data(3).dtTransOffset = 2;

                    ;% rtP.PIDController1_LowerSaturationLimit
                    section.data(4).logicalSrcIdx = 20;
                    section.data(4).dtTransOffset = 4;

                    ;% rtP.PIDController3_LowerSaturationLimit
                    section.data(5).logicalSrcIdx = 21;
                    section.data(5).dtTransOffset = 5;

                    ;% rtP.PIDController2_LowerSaturationLimit
                    section.data(6).logicalSrcIdx = 22;
                    section.data(6).dtTransOffset = 6;

                    ;% rtP.PIDController1_UpperSaturationLimit
                    section.data(7).logicalSrcIdx = 23;
                    section.data(7).dtTransOffset = 7;

                    ;% rtP.PIDController3_UpperSaturationLimit
                    section.data(8).logicalSrcIdx = 24;
                    section.data(8).dtTransOffset = 8;

                    ;% rtP.PIDController2_UpperSaturationLimit
                    section.data(9).logicalSrcIdx = 25;
                    section.data(9).dtTransOffset = 9;

            nTotData = nTotData + section.nData;
            paramMap.sections(3) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtP.PIDController1_InitialConditionForIntegrator
                    section.data(1).logicalSrcIdx = 26;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(4) = section;
            clear section

            section.nData     = 83;
            section.data(83)  = dumData; %prealloc

                    ;% rtP.AnalogFilterDesign_A_pr
                    section.data(1).logicalSrcIdx = 27;
                    section.data(1).dtTransOffset = 0;

                    ;% rtP.AnalogFilterDesign_B_pr
                    section.data(2).logicalSrcIdx = 28;
                    section.data(2).dtTransOffset = 5;

                    ;% rtP.AnalogFilterDesign_C_pr
                    section.data(3).logicalSrcIdx = 29;
                    section.data(3).dtTransOffset = 6;

                    ;% rtP.AnalogFilterDesign_InitialCondition
                    section.data(4).logicalSrcIdx = 30;
                    section.data(4).dtTransOffset = 7;

                    ;% rtP.AnalogFilterDesign1_A_pr
                    section.data(5).logicalSrcIdx = 31;
                    section.data(5).dtTransOffset = 8;

                    ;% rtP.AnalogFilterDesign1_B_pr
                    section.data(6).logicalSrcIdx = 32;
                    section.data(6).dtTransOffset = 13;

                    ;% rtP.AnalogFilterDesign1_C_pr
                    section.data(7).logicalSrcIdx = 33;
                    section.data(7).dtTransOffset = 14;

                    ;% rtP.AnalogFilterDesign1_InitialCondition
                    section.data(8).logicalSrcIdx = 34;
                    section.data(8).dtTransOffset = 15;

                    ;% rtP.AnalogFilterDesign2_A_pr
                    section.data(9).logicalSrcIdx = 35;
                    section.data(9).dtTransOffset = 16;

                    ;% rtP.AnalogFilterDesign2_B_pr
                    section.data(10).logicalSrcIdx = 36;
                    section.data(10).dtTransOffset = 21;

                    ;% rtP.AnalogFilterDesign2_C_pr
                    section.data(11).logicalSrcIdx = 37;
                    section.data(11).dtTransOffset = 22;

                    ;% rtP.AnalogFilterDesign2_InitialCondition
                    section.data(12).logicalSrcIdx = 38;
                    section.data(12).dtTransOffset = 23;

                    ;% rtP.AnalogFilterDesign3_A_pr
                    section.data(13).logicalSrcIdx = 39;
                    section.data(13).dtTransOffset = 24;

                    ;% rtP.AnalogFilterDesign3_B_pr
                    section.data(14).logicalSrcIdx = 40;
                    section.data(14).dtTransOffset = 35;

                    ;% rtP.AnalogFilterDesign3_C_pr
                    section.data(15).logicalSrcIdx = 41;
                    section.data(15).dtTransOffset = 36;

                    ;% rtP.AnalogFilterDesign3_InitialCondition
                    section.data(16).logicalSrcIdx = 42;
                    section.data(16).dtTransOffset = 37;

                    ;% rtP.AnalogFilterDesign4_A_pr
                    section.data(17).logicalSrcIdx = 43;
                    section.data(17).dtTransOffset = 38;

                    ;% rtP.AnalogFilterDesign4_B_pr
                    section.data(18).logicalSrcIdx = 44;
                    section.data(18).dtTransOffset = 49;

                    ;% rtP.AnalogFilterDesign4_C_pr
                    section.data(19).logicalSrcIdx = 45;
                    section.data(19).dtTransOffset = 50;

                    ;% rtP.AnalogFilterDesign4_InitialCondition
                    section.data(20).logicalSrcIdx = 46;
                    section.data(20).dtTransOffset = 51;

                    ;% rtP.AnalogFilterDesign5_A_pr
                    section.data(21).logicalSrcIdx = 47;
                    section.data(21).dtTransOffset = 52;

                    ;% rtP.AnalogFilterDesign5_B_pr
                    section.data(22).logicalSrcIdx = 48;
                    section.data(22).dtTransOffset = 63;

                    ;% rtP.AnalogFilterDesign5_C_pr
                    section.data(23).logicalSrcIdx = 49;
                    section.data(23).dtTransOffset = 64;

                    ;% rtP.AnalogFilterDesign5_InitialCondition
                    section.data(24).logicalSrcIdx = 50;
                    section.data(24).dtTransOffset = 65;

                    ;% rtP.AnalogFilterDesign1_A_pr_h0kmy5bicq
                    section.data(25).logicalSrcIdx = 51;
                    section.data(25).dtTransOffset = 66;

                    ;% rtP.AnalogFilterDesign1_B_pr_ew5a2lr4t2
                    section.data(26).logicalSrcIdx = 52;
                    section.data(26).dtTransOffset = 71;

                    ;% rtP.AnalogFilterDesign1_C_pr_ch4mm2g3zc
                    section.data(27).logicalSrcIdx = 53;
                    section.data(27).dtTransOffset = 72;

                    ;% rtP.AnalogFilterDesign1_InitialCondition_k3v143gesi
                    section.data(28).logicalSrcIdx = 54;
                    section.data(28).dtTransOffset = 73;

                    ;% rtP.PulseGenerator_Amp
                    section.data(29).logicalSrcIdx = 55;
                    section.data(29).dtTransOffset = 74;

                    ;% rtP.PulseGenerator_Period
                    section.data(30).logicalSrcIdx = 56;
                    section.data(30).dtTransOffset = 75;

                    ;% rtP.PulseGenerator_Duty
                    section.data(31).logicalSrcIdx = 57;
                    section.data(31).dtTransOffset = 76;

                    ;% rtP.PulseGenerator_PhaseDelay
                    section.data(32).logicalSrcIdx = 58;
                    section.data(32).dtTransOffset = 77;

                    ;% rtP.AnalogFilterDesign_A_pr_esqpqjprtf
                    section.data(33).logicalSrcIdx = 59;
                    section.data(33).dtTransOffset = 78;

                    ;% rtP.AnalogFilterDesign_B_pr_l5d4110w1d
                    section.data(34).logicalSrcIdx = 60;
                    section.data(34).dtTransOffset = 81;

                    ;% rtP.AnalogFilterDesign_C_pr_d2lrbbjghc
                    section.data(35).logicalSrcIdx = 61;
                    section.data(35).dtTransOffset = 82;

                    ;% rtP.AnalogFilterDesign_InitialCondition_pqqwkiff0r
                    section.data(36).logicalSrcIdx = 62;
                    section.data(36).dtTransOffset = 83;

                    ;% rtP.Gain2_Gain
                    section.data(37).logicalSrcIdx = 63;
                    section.data(37).dtTransOffset = 84;

                    ;% rtP.Gain3_Gain
                    section.data(38).logicalSrcIdx = 64;
                    section.data(38).dtTransOffset = 85;

                    ;% rtP.Constant_Value
                    section.data(39).logicalSrcIdx = 65;
                    section.data(39).dtTransOffset = 86;

                    ;% rtP.Constant_Value_e4jyxae25b
                    section.data(40).logicalSrcIdx = 66;
                    section.data(40).dtTransOffset = 87;

                    ;% rtP.Constant_Value_prx0zmzuez
                    section.data(41).logicalSrcIdx = 67;
                    section.data(41).dtTransOffset = 88;

                    ;% rtP.Constant1_Value
                    section.data(42).logicalSrcIdx = 68;
                    section.data(42).dtTransOffset = 89;

                    ;% rtP.DiscreteTimeIntegrator3_gainval
                    section.data(43).logicalSrcIdx = 69;
                    section.data(43).dtTransOffset = 90;

                    ;% rtP.DiscreteTimeIntegrator3_UpperSat
                    section.data(44).logicalSrcIdx = 70;
                    section.data(44).dtTransOffset = 91;

                    ;% rtP.DiscreteTimeIntegrator3_LowerSat
                    section.data(45).logicalSrcIdx = 71;
                    section.data(45).dtTransOffset = 92;

                    ;% rtP.DiscreteTimeIntegrator3_gainval_o2siosbbdr
                    section.data(46).logicalSrcIdx = 72;
                    section.data(46).dtTransOffset = 93;

                    ;% rtP.DiscreteTimeIntegrator3_UpperSat_njveboaopq
                    section.data(47).logicalSrcIdx = 73;
                    section.data(47).dtTransOffset = 94;

                    ;% rtP.DiscreteTimeIntegrator3_LowerSat_acpnkz2txi
                    section.data(48).logicalSrcIdx = 74;
                    section.data(48).dtTransOffset = 95;

                    ;% rtP.Gain2_Gain_bufpac5tbs
                    section.data(49).logicalSrcIdx = 75;
                    section.data(49).dtTransOffset = 96;

                    ;% rtP.Gain3_Gain_e1nr0mavjq
                    section.data(50).logicalSrcIdx = 76;
                    section.data(50).dtTransOffset = 97;

                    ;% rtP.Gain1_Gain
                    section.data(51).logicalSrcIdx = 77;
                    section.data(51).dtTransOffset = 98;

                    ;% rtP.Gain4_Gain
                    section.data(52).logicalSrcIdx = 78;
                    section.data(52).dtTransOffset = 99;

                    ;% rtP.DiscreteTimeIntegrator_gainval
                    section.data(53).logicalSrcIdx = 79;
                    section.data(53).dtTransOffset = 100;

                    ;% rtP.DiscreteTimeIntegrator_UpperSat
                    section.data(54).logicalSrcIdx = 80;
                    section.data(54).dtTransOffset = 101;

                    ;% rtP.DiscreteTimeIntegrator_LowerSat
                    section.data(55).logicalSrcIdx = 81;
                    section.data(55).dtTransOffset = 102;

                    ;% rtP.Gain1_Gain_owsv2iwqia
                    section.data(56).logicalSrcIdx = 82;
                    section.data(56).dtTransOffset = 103;

                    ;% rtP.Saturation2_UpperSat
                    section.data(57).logicalSrcIdx = 83;
                    section.data(57).dtTransOffset = 104;

                    ;% rtP.Saturation2_LowerSat
                    section.data(58).logicalSrcIdx = 84;
                    section.data(58).dtTransOffset = 105;

                    ;% rtP.Gain_Gain
                    section.data(59).logicalSrcIdx = 85;
                    section.data(59).dtTransOffset = 106;

                    ;% rtP.FromWs_Time0
                    section.data(60).logicalSrcIdx = 86;
                    section.data(60).dtTransOffset = 107;

                    ;% rtP.FromWs_Data0
                    section.data(61).logicalSrcIdx = 87;
                    section.data(61).dtTransOffset = 112;

                    ;% rtP.Gain2_Gain_lgyufe3n3y
                    section.data(62).logicalSrcIdx = 88;
                    section.data(62).dtTransOffset = 117;

                    ;% rtP.Gain_Gain_n3c5iuh2qk
                    section.data(63).logicalSrcIdx = 89;
                    section.data(63).dtTransOffset = 118;

                    ;% rtP.Gain1_Gain_cuaiqtkau5
                    section.data(64).logicalSrcIdx = 90;
                    section.data(64).dtTransOffset = 119;

                    ;% rtP.Gain4_Gain_dum3dkp5wn
                    section.data(65).logicalSrcIdx = 91;
                    section.data(65).dtTransOffset = 120;

                    ;% rtP.Gain2_Gain_m2442d4sfc
                    section.data(66).logicalSrcIdx = 92;
                    section.data(66).dtTransOffset = 121;

                    ;% rtP.Gain3_Gain_baedkupsze
                    section.data(67).logicalSrcIdx = 93;
                    section.data(67).dtTransOffset = 122;

                    ;% rtP.Constant1_Value_cec3dpoe5t
                    section.data(68).logicalSrcIdx = 94;
                    section.data(68).dtTransOffset = 123;

                    ;% rtP.Constant3_Value
                    section.data(69).logicalSrcIdx = 95;
                    section.data(69).dtTransOffset = 124;

                    ;% rtP.Constant5_Value
                    section.data(70).logicalSrcIdx = 96;
                    section.data(70).dtTransOffset = 125;

                    ;% rtP.Constant1_Value_fuoewzrkks
                    section.data(71).logicalSrcIdx = 97;
                    section.data(71).dtTransOffset = 126;

                    ;% rtP.Constant2_Value
                    section.data(72).logicalSrcIdx = 98;
                    section.data(72).dtTransOffset = 127;

                    ;% rtP.Constant1_Value_p1324vfsr3
                    section.data(73).logicalSrcIdx = 99;
                    section.data(73).dtTransOffset = 128;

                    ;% rtP.Constant1_Value_db5wbste14
                    section.data(74).logicalSrcIdx = 100;
                    section.data(74).dtTransOffset = 129;

                    ;% rtP.Constant1_Value_arpzt5qlzk
                    section.data(75).logicalSrcIdx = 101;
                    section.data(75).dtTransOffset = 130;

                    ;% rtP.Constant2_Value_iedxtooqmk
                    section.data(76).logicalSrcIdx = 102;
                    section.data(76).dtTransOffset = 131;

                    ;% rtP.Constant2_Value_ombtisyb12
                    section.data(77).logicalSrcIdx = 103;
                    section.data(77).dtTransOffset = 132;

                    ;% rtP.Constant1_Value_i5c5nfcqn0
                    section.data(78).logicalSrcIdx = 104;
                    section.data(78).dtTransOffset = 133;

                    ;% rtP.Constant1_Value_ghv5aa4po2
                    section.data(79).logicalSrcIdx = 105;
                    section.data(79).dtTransOffset = 134;

                    ;% rtP.Constant1_Value_dlowd15ti4
                    section.data(80).logicalSrcIdx = 106;
                    section.data(80).dtTransOffset = 135;

                    ;% rtP.Constant2_Value_cfaqape04n
                    section.data(81).logicalSrcIdx = 107;
                    section.data(81).dtTransOffset = 136;

                    ;% rtP.Constant2_Value_puzy4v1jc3
                    section.data(82).logicalSrcIdx = 108;
                    section.data(82).dtTransOffset = 137;

                    ;% rtP.Constant2_Value_bmnavpjpcf
                    section.data(83).logicalSrcIdx = 109;
                    section.data(83).dtTransOffset = 138;

            nTotData = nTotData + section.nData;
            paramMap.sections(5) = section;
            clear section

            section.nData     = 49;
            section.data(49)  = dumData; %prealloc

                    ;% rtP.Constant1_Value_fpaq0utenz
                    section.data(1).logicalSrcIdx = 110;
                    section.data(1).dtTransOffset = 0;

                    ;% rtP.Constant1_Value_pe5vj0iriy
                    section.data(2).logicalSrcIdx = 111;
                    section.data(2).dtTransOffset = 1;

                    ;% rtP.Gain_Gain_oneshwnrhn
                    section.data(3).logicalSrcIdx = 112;
                    section.data(3).dtTransOffset = 2;

                    ;% rtP.Gain1_Gain_d0pmjscvt0
                    section.data(4).logicalSrcIdx = 113;
                    section.data(4).dtTransOffset = 3;

                    ;% rtP.Gain2_Gain_c5zyi33wrb
                    section.data(5).logicalSrcIdx = 114;
                    section.data(5).dtTransOffset = 4;

                    ;% rtP.Gain_Gain_nggjdhdyc1
                    section.data(6).logicalSrcIdx = 115;
                    section.data(6).dtTransOffset = 5;

                    ;% rtP.Gain1_Gain_dhl1phxitf
                    section.data(7).logicalSrcIdx = 116;
                    section.data(7).dtTransOffset = 6;

                    ;% rtP.DiscreteTimeIntegrator1_gainval
                    section.data(8).logicalSrcIdx = 117;
                    section.data(8).dtTransOffset = 7;

                    ;% rtP.DiscreteTimeIntegrator1_IC
                    section.data(9).logicalSrcIdx = 118;
                    section.data(9).dtTransOffset = 8;

                    ;% rtP.Gain2_Gain_nyrqrcnyqt
                    section.data(10).logicalSrcIdx = 119;
                    section.data(10).dtTransOffset = 9;

                    ;% rtP.Integrator_gainval
                    section.data(11).logicalSrcIdx = 120;
                    section.data(11).dtTransOffset = 10;

                    ;% rtP.Integrator_gainval_gqdjj5igji
                    section.data(12).logicalSrcIdx = 121;
                    section.data(12).dtTransOffset = 11;

                    ;% rtP.DiscreteTimeIntegrator_gainval_k25juj44ov
                    section.data(13).logicalSrcIdx = 122;
                    section.data(13).dtTransOffset = 12;

                    ;% rtP.DiscreteTimeIntegrator_IC
                    section.data(14).logicalSrcIdx = 123;
                    section.data(14).dtTransOffset = 13;

                    ;% rtP.ASwitch_Threshold
                    section.data(15).logicalSrcIdx = 124;
                    section.data(15).dtTransOffset = 14;

                    ;% rtP.Gain_Gain_gt5xi45qct
                    section.data(16).logicalSrcIdx = 125;
                    section.data(16).dtTransOffset = 15;

                    ;% rtP.Gain1_Gain_cpamektdhq
                    section.data(17).logicalSrcIdx = 126;
                    section.data(17).dtTransOffset = 16;

                    ;% rtP.BSwitch_Threshold
                    section.data(18).logicalSrcIdx = 127;
                    section.data(18).dtTransOffset = 17;

                    ;% rtP.CSwitch_Threshold
                    section.data(19).logicalSrcIdx = 128;
                    section.data(19).dtTransOffset = 18;

                    ;% rtP.Gain1_Gain_d2r1btvvwg
                    section.data(20).logicalSrcIdx = 129;
                    section.data(20).dtTransOffset = 19;

                    ;% rtP.Gain1_Gain_o051fegvds
                    section.data(21).logicalSrcIdx = 130;
                    section.data(21).dtTransOffset = 20;

                    ;% rtP.Gain2_Gain_fpelshvuq5
                    section.data(22).logicalSrcIdx = 131;
                    section.data(22).dtTransOffset = 21;

                    ;% rtP.Gain_Gain_bpfw2sk42p
                    section.data(23).logicalSrcIdx = 132;
                    section.data(23).dtTransOffset = 22;

                    ;% rtP.Gain2_Gain_crytncxhkk
                    section.data(24).logicalSrcIdx = 133;
                    section.data(24).dtTransOffset = 23;

                    ;% rtP.Gain_Gain_lsczmwd1h2
                    section.data(25).logicalSrcIdx = 134;
                    section.data(25).dtTransOffset = 24;

                    ;% rtP.Gain1_Gain_j1zbr4lzxq
                    section.data(26).logicalSrcIdx = 135;
                    section.data(26).dtTransOffset = 25;

                    ;% rtP.Switch_Threshold
                    section.data(27).logicalSrcIdx = 136;
                    section.data(27).dtTransOffset = 26;

                    ;% rtP.Gain_Gain_hfbnedsnqk
                    section.data(28).logicalSrcIdx = 137;
                    section.data(28).dtTransOffset = 27;

                    ;% rtP.Switch1_Threshold
                    section.data(29).logicalSrcIdx = 138;
                    section.data(29).dtTransOffset = 28;

                    ;% rtP.Gain2_Gain_mqqw0m41vg
                    section.data(30).logicalSrcIdx = 139;
                    section.data(30).dtTransOffset = 29;

                    ;% rtP.Gain_Gain_dd1zo3e4je
                    section.data(31).logicalSrcIdx = 140;
                    section.data(31).dtTransOffset = 30;

                    ;% rtP.Constant1_Value_pfphbi3aj2
                    section.data(32).logicalSrcIdx = 141;
                    section.data(32).dtTransOffset = 31;

                    ;% rtP.Constant_Value_fad045x02c
                    section.data(33).logicalSrcIdx = 142;
                    section.data(33).dtTransOffset = 32;

                    ;% rtP.Clamping_zero_Value
                    section.data(34).logicalSrcIdx = 143;
                    section.data(34).dtTransOffset = 33;

                    ;% rtP.Constant2_Value_n4cnemylwa
                    section.data(35).logicalSrcIdx = 144;
                    section.data(35).dtTransOffset = 34;

                    ;% rtP.Clamping_zero_Value_n2or5cqygv
                    section.data(36).logicalSrcIdx = 145;
                    section.data(36).dtTransOffset = 35;

                    ;% rtP.Constant3_Value_lzmoq4j5e0
                    section.data(37).logicalSrcIdx = 146;
                    section.data(37).dtTransOffset = 36;

                    ;% rtP.Constant1_Value_l2ipogf1kx
                    section.data(38).logicalSrcIdx = 147;
                    section.data(38).dtTransOffset = 37;

                    ;% rtP.RateTransition_InitialCondition
                    section.data(39).logicalSrcIdx = 148;
                    section.data(39).dtTransOffset = 38;

                    ;% rtP.RateTransition1_InitialCondition
                    section.data(40).logicalSrcIdx = 149;
                    section.data(40).dtTransOffset = 39;

                    ;% rtP.RateTransition2_InitialCondition
                    section.data(41).logicalSrcIdx = 150;
                    section.data(41).dtTransOffset = 40;

                    ;% rtP.RateTransition8_InitialCondition
                    section.data(42).logicalSrcIdx = 151;
                    section.data(42).dtTransOffset = 41;

                    ;% rtP.RateTransition3_InitialCondition
                    section.data(43).logicalSrcIdx = 152;
                    section.data(43).dtTransOffset = 42;

                    ;% rtP.Constant_Value_pspbithpw4
                    section.data(44).logicalSrcIdx = 153;
                    section.data(44).dtTransOffset = 43;

                    ;% rtP.Constant_Value_ah0pp224du
                    section.data(45).logicalSrcIdx = 154;
                    section.data(45).dtTransOffset = 44;

                    ;% rtP.Switch_Threshold_buydduua1q
                    section.data(46).logicalSrcIdx = 155;
                    section.data(46).dtTransOffset = 45;

                    ;% rtP.Constant1_Value_a1crlzduby
                    section.data(47).logicalSrcIdx = 156;
                    section.data(47).dtTransOffset = 46;

                    ;% rtP.Constant2_Value_e5cors3m1f
                    section.data(48).logicalSrcIdx = 157;
                    section.data(48).dtTransOffset = 47;

                    ;% rtP.Constant3_Value_fveq5hyrqd
                    section.data(49).logicalSrcIdx = 158;
                    section.data(49).dtTransOffset = 48;

            nTotData = nTotData + section.nData;
            paramMap.sections(6) = section;
            clear section

            section.nData     = 48;
            section.data(48)  = dumData; %prealloc

                    ;% rtP.AnalogFilterDesign_A_ir
                    section.data(1).logicalSrcIdx = 159;
                    section.data(1).dtTransOffset = 0;

                    ;% rtP.AnalogFilterDesign_A_jc
                    section.data(2).logicalSrcIdx = 160;
                    section.data(2).dtTransOffset = 5;

                    ;% rtP.AnalogFilterDesign_B_ir
                    section.data(3).logicalSrcIdx = 161;
                    section.data(3).dtTransOffset = 9;

                    ;% rtP.AnalogFilterDesign_B_jc
                    section.data(4).logicalSrcIdx = 162;
                    section.data(4).dtTransOffset = 10;

                    ;% rtP.AnalogFilterDesign_C_ir
                    section.data(5).logicalSrcIdx = 163;
                    section.data(5).dtTransOffset = 12;

                    ;% rtP.AnalogFilterDesign_C_jc
                    section.data(6).logicalSrcIdx = 164;
                    section.data(6).dtTransOffset = 13;

                    ;% rtP.AnalogFilterDesign1_A_ir
                    section.data(7).logicalSrcIdx = 165;
                    section.data(7).dtTransOffset = 17;

                    ;% rtP.AnalogFilterDesign1_A_jc
                    section.data(8).logicalSrcIdx = 166;
                    section.data(8).dtTransOffset = 22;

                    ;% rtP.AnalogFilterDesign1_B_ir
                    section.data(9).logicalSrcIdx = 167;
                    section.data(9).dtTransOffset = 26;

                    ;% rtP.AnalogFilterDesign1_B_jc
                    section.data(10).logicalSrcIdx = 168;
                    section.data(10).dtTransOffset = 27;

                    ;% rtP.AnalogFilterDesign1_C_ir
                    section.data(11).logicalSrcIdx = 169;
                    section.data(11).dtTransOffset = 29;

                    ;% rtP.AnalogFilterDesign1_C_jc
                    section.data(12).logicalSrcIdx = 170;
                    section.data(12).dtTransOffset = 30;

                    ;% rtP.AnalogFilterDesign2_A_ir
                    section.data(13).logicalSrcIdx = 171;
                    section.data(13).dtTransOffset = 34;

                    ;% rtP.AnalogFilterDesign2_A_jc
                    section.data(14).logicalSrcIdx = 172;
                    section.data(14).dtTransOffset = 39;

                    ;% rtP.AnalogFilterDesign2_B_ir
                    section.data(15).logicalSrcIdx = 173;
                    section.data(15).dtTransOffset = 43;

                    ;% rtP.AnalogFilterDesign2_B_jc
                    section.data(16).logicalSrcIdx = 174;
                    section.data(16).dtTransOffset = 44;

                    ;% rtP.AnalogFilterDesign2_C_ir
                    section.data(17).logicalSrcIdx = 175;
                    section.data(17).dtTransOffset = 46;

                    ;% rtP.AnalogFilterDesign2_C_jc
                    section.data(18).logicalSrcIdx = 176;
                    section.data(18).dtTransOffset = 47;

                    ;% rtP.AnalogFilterDesign3_A_ir
                    section.data(19).logicalSrcIdx = 177;
                    section.data(19).dtTransOffset = 51;

                    ;% rtP.AnalogFilterDesign3_A_jc
                    section.data(20).logicalSrcIdx = 178;
                    section.data(20).dtTransOffset = 62;

                    ;% rtP.AnalogFilterDesign3_B_ir
                    section.data(21).logicalSrcIdx = 179;
                    section.data(21).dtTransOffset = 69;

                    ;% rtP.AnalogFilterDesign3_B_jc
                    section.data(22).logicalSrcIdx = 180;
                    section.data(22).dtTransOffset = 70;

                    ;% rtP.AnalogFilterDesign3_C_ir
                    section.data(23).logicalSrcIdx = 181;
                    section.data(23).dtTransOffset = 72;

                    ;% rtP.AnalogFilterDesign3_C_jc
                    section.data(24).logicalSrcIdx = 182;
                    section.data(24).dtTransOffset = 73;

                    ;% rtP.AnalogFilterDesign4_A_ir
                    section.data(25).logicalSrcIdx = 183;
                    section.data(25).dtTransOffset = 80;

                    ;% rtP.AnalogFilterDesign4_A_jc
                    section.data(26).logicalSrcIdx = 184;
                    section.data(26).dtTransOffset = 91;

                    ;% rtP.AnalogFilterDesign4_B_ir
                    section.data(27).logicalSrcIdx = 185;
                    section.data(27).dtTransOffset = 98;

                    ;% rtP.AnalogFilterDesign4_B_jc
                    section.data(28).logicalSrcIdx = 186;
                    section.data(28).dtTransOffset = 99;

                    ;% rtP.AnalogFilterDesign4_C_ir
                    section.data(29).logicalSrcIdx = 187;
                    section.data(29).dtTransOffset = 101;

                    ;% rtP.AnalogFilterDesign4_C_jc
                    section.data(30).logicalSrcIdx = 188;
                    section.data(30).dtTransOffset = 102;

                    ;% rtP.AnalogFilterDesign5_A_ir
                    section.data(31).logicalSrcIdx = 189;
                    section.data(31).dtTransOffset = 109;

                    ;% rtP.AnalogFilterDesign5_A_jc
                    section.data(32).logicalSrcIdx = 190;
                    section.data(32).dtTransOffset = 120;

                    ;% rtP.AnalogFilterDesign5_B_ir
                    section.data(33).logicalSrcIdx = 191;
                    section.data(33).dtTransOffset = 127;

                    ;% rtP.AnalogFilterDesign5_B_jc
                    section.data(34).logicalSrcIdx = 192;
                    section.data(34).dtTransOffset = 128;

                    ;% rtP.AnalogFilterDesign5_C_ir
                    section.data(35).logicalSrcIdx = 193;
                    section.data(35).dtTransOffset = 130;

                    ;% rtP.AnalogFilterDesign5_C_jc
                    section.data(36).logicalSrcIdx = 194;
                    section.data(36).dtTransOffset = 131;

                    ;% rtP.AnalogFilterDesign1_A_ir_hrenrgccbq
                    section.data(37).logicalSrcIdx = 195;
                    section.data(37).dtTransOffset = 138;

                    ;% rtP.AnalogFilterDesign1_A_jc_lbh1btnh5f
                    section.data(38).logicalSrcIdx = 196;
                    section.data(38).dtTransOffset = 143;

                    ;% rtP.AnalogFilterDesign1_B_ir_fpqzlg1kvc
                    section.data(39).logicalSrcIdx = 197;
                    section.data(39).dtTransOffset = 147;

                    ;% rtP.AnalogFilterDesign1_B_jc_ghy2lei3av
                    section.data(40).logicalSrcIdx = 198;
                    section.data(40).dtTransOffset = 148;

                    ;% rtP.AnalogFilterDesign1_C_ir_ft0xxxbkg4
                    section.data(41).logicalSrcIdx = 199;
                    section.data(41).dtTransOffset = 150;

                    ;% rtP.AnalogFilterDesign1_C_jc_bi43o0wxhg
                    section.data(42).logicalSrcIdx = 200;
                    section.data(42).dtTransOffset = 151;

                    ;% rtP.AnalogFilterDesign_A_ir_dogadco1zw
                    section.data(43).logicalSrcIdx = 201;
                    section.data(43).dtTransOffset = 155;

                    ;% rtP.AnalogFilterDesign_A_jc_odmcc04tok
                    section.data(44).logicalSrcIdx = 202;
                    section.data(44).dtTransOffset = 158;

                    ;% rtP.AnalogFilterDesign_B_ir_c20unw4tq1
                    section.data(45).logicalSrcIdx = 203;
                    section.data(45).dtTransOffset = 161;

                    ;% rtP.AnalogFilterDesign_B_jc_jbvp1zaaeo
                    section.data(46).logicalSrcIdx = 204;
                    section.data(46).dtTransOffset = 162;

                    ;% rtP.AnalogFilterDesign_C_ir_kzmexqw5ri
                    section.data(47).logicalSrcIdx = 205;
                    section.data(47).dtTransOffset = 164;

                    ;% rtP.AnalogFilterDesign_C_jc_e5mtimz5tp
                    section.data(48).logicalSrcIdx = 206;
                    section.data(48).dtTransOffset = 165;

            nTotData = nTotData + section.nData;
            paramMap.sections(7) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% rtP.Constant1_Value_odajvcsv3r
                    section.data(1).logicalSrcIdx = 207;
                    section.data(1).dtTransOffset = 0;

                    ;% rtP.Clamping_zero_Value_gmmqgeo1e4
                    section.data(2).logicalSrcIdx = 208;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            paramMap.sections(8) = section;
            clear section

            section.nData     = 12;
            section.data(12)  = dumData; %prealloc

                    ;% rtP.Constant_Value_jxwhvocfhb
                    section.data(1).logicalSrcIdx = 209;
                    section.data(1).dtTransOffset = 0;

                    ;% rtP.Constant2_Value_i2m45uwk2o
                    section.data(2).logicalSrcIdx = 210;
                    section.data(2).dtTransOffset = 1;

                    ;% rtP.Constant3_Value_bymcbl0414
                    section.data(3).logicalSrcIdx = 211;
                    section.data(3).dtTransOffset = 2;

                    ;% rtP.Constant4_Value
                    section.data(4).logicalSrcIdx = 212;
                    section.data(4).dtTransOffset = 3;

                    ;% rtP.Constant_Value_jhbksipzdc
                    section.data(5).logicalSrcIdx = 213;
                    section.data(5).dtTransOffset = 4;

                    ;% rtP.Constant2_Value_j12qjlnlzg
                    section.data(6).logicalSrcIdx = 214;
                    section.data(6).dtTransOffset = 5;

                    ;% rtP.Constant3_Value_gvheyotvnt
                    section.data(7).logicalSrcIdx = 215;
                    section.data(7).dtTransOffset = 6;

                    ;% rtP.Constant4_Value_hfhut001zy
                    section.data(8).logicalSrcIdx = 216;
                    section.data(8).dtTransOffset = 7;

                    ;% rtP.Constant_Value_oqmhouwrxr
                    section.data(9).logicalSrcIdx = 217;
                    section.data(9).dtTransOffset = 8;

                    ;% rtP.Constant2_Value_gdlubdifra
                    section.data(10).logicalSrcIdx = 218;
                    section.data(10).dtTransOffset = 9;

                    ;% rtP.Constant3_Value_nanqjpbqvw
                    section.data(11).logicalSrcIdx = 219;
                    section.data(11).dtTransOffset = 10;

                    ;% rtP.Constant4_Value_ge5isbbxow
                    section.data(12).logicalSrcIdx = 220;
                    section.data(12).dtTransOffset = 11;

            nTotData = nTotData + section.nData;
            paramMap.sections(9) = section;
            clear section


            ;%
            ;% Non-auto Data (parameter)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        paramMap.nTotData = nTotData;



    ;%**************************
    ;% Create Block Output Map *
    ;%**************************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 3;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc sigMap
        ;%
        sigMap.nSections           = nTotSects;
        sigMap.sectIdxOffset       = sectIdxOffset;
            sigMap.sections(nTotSects) = dumSection; %prealloc
        sigMap.nTotData            = -1;

        ;%
        ;% Auto data (rtB)
        ;%
            section.nData     = 21;
            section.data(21)  = dumData; %prealloc

                    ;% rtB.avkcbyy3ru
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% rtB.ptas5mx2xx
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 3;

                    ;% rtB.iyvrnoncql
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 6;

                    ;% rtB.lz5lj5ytco
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 7;

                    ;% rtB.jielxbq1gv
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 8;

                    ;% rtB.fgw4v4wm4g
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 9;

                    ;% rtB.ouiqfsyu43
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 10;

                    ;% rtB.acjaxnsuyo
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 11;

                    ;% rtB.c1syzcnvq0
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 12;

                    ;% rtB.kpb21alagy
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 13;

                    ;% rtB.ikmh2tfryy
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 14;

                    ;% rtB.ah0extvo4t
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 15;

                    ;% rtB.hqrlwn2gih
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 16;

                    ;% rtB.jeobpjpcy3
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 17;

                    ;% rtB.oy1uirggpc
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 18;

                    ;% rtB.lwjmxasb2z
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 19;

                    ;% rtB.ajtg2x2b41
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 20;

                    ;% rtB.logsazcj2d
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 21;

                    ;% rtB.hqgkqxg4zr
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 22;

                    ;% rtB.j5g3qzjurz
                    section.data(20).logicalSrcIdx = 19;
                    section.data(20).dtTransOffset = 23;

                    ;% rtB.exsy54mv4x
                    section.data(21).logicalSrcIdx = 20;
                    section.data(21).dtTransOffset = 24;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section

            section.nData     = 70;
            section.data(70)  = dumData; %prealloc

                    ;% rtB.hnrjpbhtyb
                    section.data(1).logicalSrcIdx = 21;
                    section.data(1).dtTransOffset = 0;

                    ;% rtB.kif4jng5eq
                    section.data(2).logicalSrcIdx = 22;
                    section.data(2).dtTransOffset = 1;

                    ;% rtB.n4szfkmgux
                    section.data(3).logicalSrcIdx = 23;
                    section.data(3).dtTransOffset = 2;

                    ;% rtB.fvwparn2lf
                    section.data(4).logicalSrcIdx = 24;
                    section.data(4).dtTransOffset = 3;

                    ;% rtB.lyy5l51j1r
                    section.data(5).logicalSrcIdx = 25;
                    section.data(5).dtTransOffset = 4;

                    ;% rtB.owirr1gzew
                    section.data(6).logicalSrcIdx = 26;
                    section.data(6).dtTransOffset = 5;

                    ;% rtB.modaikvwk2
                    section.data(7).logicalSrcIdx = 27;
                    section.data(7).dtTransOffset = 6;

                    ;% rtB.oekg5cjnsz
                    section.data(8).logicalSrcIdx = 28;
                    section.data(8).dtTransOffset = 7;

                    ;% rtB.ezk2tehwll
                    section.data(9).logicalSrcIdx = 29;
                    section.data(9).dtTransOffset = 8;

                    ;% rtB.haqol3cjgg
                    section.data(10).logicalSrcIdx = 30;
                    section.data(10).dtTransOffset = 9;

                    ;% rtB.orihl2n4h3
                    section.data(11).logicalSrcIdx = 31;
                    section.data(11).dtTransOffset = 10;

                    ;% rtB.cm34cwonv3
                    section.data(12).logicalSrcIdx = 32;
                    section.data(12).dtTransOffset = 11;

                    ;% rtB.lknhr4vxtr
                    section.data(13).logicalSrcIdx = 33;
                    section.data(13).dtTransOffset = 12;

                    ;% rtB.cnm3x1s5lo
                    section.data(14).logicalSrcIdx = 34;
                    section.data(14).dtTransOffset = 13;

                    ;% rtB.ow4uvzz2pj
                    section.data(15).logicalSrcIdx = 35;
                    section.data(15).dtTransOffset = 14;

                    ;% rtB.k0o4fvzzy3
                    section.data(16).logicalSrcIdx = 36;
                    section.data(16).dtTransOffset = 15;

                    ;% rtB.lit4m00nbl
                    section.data(17).logicalSrcIdx = 37;
                    section.data(17).dtTransOffset = 16;

                    ;% rtB.mrd41buyxt
                    section.data(18).logicalSrcIdx = 38;
                    section.data(18).dtTransOffset = 17;

                    ;% rtB.pntkd2uyvv
                    section.data(19).logicalSrcIdx = 39;
                    section.data(19).dtTransOffset = 18;

                    ;% rtB.oxcrb4vtyb
                    section.data(20).logicalSrcIdx = 40;
                    section.data(20).dtTransOffset = 19;

                    ;% rtB.isprk1at5s
                    section.data(21).logicalSrcIdx = 41;
                    section.data(21).dtTransOffset = 20;

                    ;% rtB.c5jdvrisaz
                    section.data(22).logicalSrcIdx = 42;
                    section.data(22).dtTransOffset = 21;

                    ;% rtB.mu2g0xzmlu
                    section.data(23).logicalSrcIdx = 43;
                    section.data(23).dtTransOffset = 22;

                    ;% rtB.imeh0bgjnw
                    section.data(24).logicalSrcIdx = 44;
                    section.data(24).dtTransOffset = 23;

                    ;% rtB.e0mzutezmn
                    section.data(25).logicalSrcIdx = 45;
                    section.data(25).dtTransOffset = 24;

                    ;% rtB.luh55v3bwu
                    section.data(26).logicalSrcIdx = 46;
                    section.data(26).dtTransOffset = 25;

                    ;% rtB.md15iiloqt
                    section.data(27).logicalSrcIdx = 47;
                    section.data(27).dtTransOffset = 26;

                    ;% rtB.krxowr1za1
                    section.data(28).logicalSrcIdx = 48;
                    section.data(28).dtTransOffset = 27;

                    ;% rtB.bwxxvrlgaj
                    section.data(29).logicalSrcIdx = 49;
                    section.data(29).dtTransOffset = 28;

                    ;% rtB.c1odu2gdtj
                    section.data(30).logicalSrcIdx = 50;
                    section.data(30).dtTransOffset = 29;

                    ;% rtB.ogxod1b2u3
                    section.data(31).logicalSrcIdx = 51;
                    section.data(31).dtTransOffset = 30;

                    ;% rtB.lqedrpdjvq
                    section.data(32).logicalSrcIdx = 52;
                    section.data(32).dtTransOffset = 31;

                    ;% rtB.hujs41lxa1
                    section.data(33).logicalSrcIdx = 53;
                    section.data(33).dtTransOffset = 32;

                    ;% rtB.ij0emyqotr
                    section.data(34).logicalSrcIdx = 54;
                    section.data(34).dtTransOffset = 33;

                    ;% rtB.czad505sp3
                    section.data(35).logicalSrcIdx = 55;
                    section.data(35).dtTransOffset = 34;

                    ;% rtB.oy5uuprwrz
                    section.data(36).logicalSrcIdx = 56;
                    section.data(36).dtTransOffset = 35;

                    ;% rtB.hfw2v3eciw
                    section.data(37).logicalSrcIdx = 57;
                    section.data(37).dtTransOffset = 36;

                    ;% rtB.a1dv31bkl5
                    section.data(38).logicalSrcIdx = 58;
                    section.data(38).dtTransOffset = 37;

                    ;% rtB.fe5da5vw1v
                    section.data(39).logicalSrcIdx = 59;
                    section.data(39).dtTransOffset = 38;

                    ;% rtB.izwpvpxlts
                    section.data(40).logicalSrcIdx = 60;
                    section.data(40).dtTransOffset = 39;

                    ;% rtB.gpl4ohobjp
                    section.data(41).logicalSrcIdx = 61;
                    section.data(41).dtTransOffset = 40;

                    ;% rtB.b15ggaqysc
                    section.data(42).logicalSrcIdx = 62;
                    section.data(42).dtTransOffset = 41;

                    ;% rtB.fdhox1t1ny
                    section.data(43).logicalSrcIdx = 63;
                    section.data(43).dtTransOffset = 42;

                    ;% rtB.cxpc4e4kit
                    section.data(44).logicalSrcIdx = 64;
                    section.data(44).dtTransOffset = 43;

                    ;% rtB.oaogaf1p5f
                    section.data(45).logicalSrcIdx = 65;
                    section.data(45).dtTransOffset = 44;

                    ;% rtB.j0ybbliyam
                    section.data(46).logicalSrcIdx = 66;
                    section.data(46).dtTransOffset = 45;

                    ;% rtB.lubu1u2ru4
                    section.data(47).logicalSrcIdx = 67;
                    section.data(47).dtTransOffset = 46;

                    ;% rtB.kwir5smtvi
                    section.data(48).logicalSrcIdx = 68;
                    section.data(48).dtTransOffset = 47;

                    ;% rtB.nacsw2wv2y
                    section.data(49).logicalSrcIdx = 69;
                    section.data(49).dtTransOffset = 48;

                    ;% rtB.m0psoaixxy
                    section.data(50).logicalSrcIdx = 70;
                    section.data(50).dtTransOffset = 49;

                    ;% rtB.kybjyzwqma
                    section.data(51).logicalSrcIdx = 71;
                    section.data(51).dtTransOffset = 50;

                    ;% rtB.cqzn2b2kj2
                    section.data(52).logicalSrcIdx = 72;
                    section.data(52).dtTransOffset = 51;

                    ;% rtB.gs5kavedxi
                    section.data(53).logicalSrcIdx = 73;
                    section.data(53).dtTransOffset = 52;

                    ;% rtB.bt3fcv3v3w
                    section.data(54).logicalSrcIdx = 74;
                    section.data(54).dtTransOffset = 53;

                    ;% rtB.nk3bpfyhq2
                    section.data(55).logicalSrcIdx = 75;
                    section.data(55).dtTransOffset = 54;

                    ;% rtB.oa4nu2h02a
                    section.data(56).logicalSrcIdx = 76;
                    section.data(56).dtTransOffset = 55;

                    ;% rtB.ll43tv0wht
                    section.data(57).logicalSrcIdx = 77;
                    section.data(57).dtTransOffset = 56;

                    ;% rtB.bvspyalpkj
                    section.data(58).logicalSrcIdx = 78;
                    section.data(58).dtTransOffset = 57;

                    ;% rtB.b2gfisg0eh
                    section.data(59).logicalSrcIdx = 79;
                    section.data(59).dtTransOffset = 58;

                    ;% rtB.nkfg1ddf1g
                    section.data(60).logicalSrcIdx = 80;
                    section.data(60).dtTransOffset = 59;

                    ;% rtB.edmswnt5ng
                    section.data(61).logicalSrcIdx = 81;
                    section.data(61).dtTransOffset = 60;

                    ;% rtB.dpomenlimv
                    section.data(62).logicalSrcIdx = 82;
                    section.data(62).dtTransOffset = 61;

                    ;% rtB.ezlw3p4p00
                    section.data(63).logicalSrcIdx = 83;
                    section.data(63).dtTransOffset = 62;

                    ;% rtB.jzhluxfqhc
                    section.data(64).logicalSrcIdx = 84;
                    section.data(64).dtTransOffset = 63;

                    ;% rtB.e0rj1hvaeo
                    section.data(65).logicalSrcIdx = 85;
                    section.data(65).dtTransOffset = 64;

                    ;% rtB.jumrg4wdv0
                    section.data(66).logicalSrcIdx = 86;
                    section.data(66).dtTransOffset = 65;

                    ;% rtB.esnhg1urb0
                    section.data(67).logicalSrcIdx = 87;
                    section.data(67).dtTransOffset = 66;

                    ;% rtB.kxtv0fhkws
                    section.data(68).logicalSrcIdx = 88;
                    section.data(68).dtTransOffset = 67;

                    ;% rtB.o1qptmrlo4
                    section.data(69).logicalSrcIdx = 89;
                    section.data(69).dtTransOffset = 68;

                    ;% rtB.fd2nlplojn
                    section.data(70).logicalSrcIdx = 90;
                    section.data(70).dtTransOffset = 69;

            nTotData = nTotData + section.nData;
            sigMap.sections(2) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtB.irpxyowq0z
                    section.data(1).logicalSrcIdx = 91;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(3) = section;
            clear section


            ;%
            ;% Non-auto Data (signal)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        sigMap.nTotData = nTotData;



    ;%*******************
    ;% Create DWork Map *
    ;%*******************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 7;
        sectIdxOffset = 3;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc dworkMap
        ;%
        dworkMap.nSections           = nTotSects;
        dworkMap.sectIdxOffset       = sectIdxOffset;
            dworkMap.sections(nTotSects) = dumSection; %prealloc
        dworkMap.nTotData            = -1;

        ;%
        ;% Auto data (rtDW)
        ;%
            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% rtDW.ixn3ky1f2r
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.hxrufsyg2z
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.bkcf3qca2q
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% rtDW.ejqmpqbi05
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 32;
            section.data(32)  = dumData; %prealloc

                    ;% rtDW.ofbl3m3sl1.LoggedData
                    section.data(1).logicalSrcIdx = 4;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.ayei34apxt.LoggedData
                    section.data(2).logicalSrcIdx = 5;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.i21c1ummfn.LoggedData
                    section.data(3).logicalSrcIdx = 6;
                    section.data(3).dtTransOffset = 2;

                    ;% rtDW.cwf0tqdxqc.TimePtr
                    section.data(4).logicalSrcIdx = 7;
                    section.data(4).dtTransOffset = 3;

                    ;% rtDW.nqgxcegx0u.LoggedData
                    section.data(5).logicalSrcIdx = 8;
                    section.data(5).dtTransOffset = 4;

                    ;% rtDW.kvvzwyojpd.LoggedData
                    section.data(6).logicalSrcIdx = 9;
                    section.data(6).dtTransOffset = 6;

                    ;% rtDW.mzzxvadqv1.LoggedData
                    section.data(7).logicalSrcIdx = 10;
                    section.data(7).dtTransOffset = 8;

                    ;% rtDW.fcr4huss3o.LoggedData
                    section.data(8).logicalSrcIdx = 11;
                    section.data(8).dtTransOffset = 9;

                    ;% rtDW.jve5mdx5l2.LoggedData
                    section.data(9).logicalSrcIdx = 12;
                    section.data(9).dtTransOffset = 10;

                    ;% rtDW.kd1p13on4q.LoggedData
                    section.data(10).logicalSrcIdx = 13;
                    section.data(10).dtTransOffset = 11;

                    ;% rtDW.ig0wdpd3dd.LoggedData
                    section.data(11).logicalSrcIdx = 14;
                    section.data(11).dtTransOffset = 13;

                    ;% rtDW.p1lafot4yj.LoggedData
                    section.data(12).logicalSrcIdx = 15;
                    section.data(12).dtTransOffset = 15;

                    ;% rtDW.lm2e0pu11e.LoggedData
                    section.data(13).logicalSrcIdx = 16;
                    section.data(13).dtTransOffset = 16;

                    ;% rtDW.jcyl3yobx2.LoggedData
                    section.data(14).logicalSrcIdx = 17;
                    section.data(14).dtTransOffset = 17;

                    ;% rtDW.ba0latgw4c.LoggedData
                    section.data(15).logicalSrcIdx = 18;
                    section.data(15).dtTransOffset = 19;

                    ;% rtDW.mmsqjiwtxv.LoggedData
                    section.data(16).logicalSrcIdx = 19;
                    section.data(16).dtTransOffset = 20;

                    ;% rtDW.ay1mkrwhhv.LoggedData
                    section.data(17).logicalSrcIdx = 20;
                    section.data(17).dtTransOffset = 23;

                    ;% rtDW.covfqhxwb4.LoggedData
                    section.data(18).logicalSrcIdx = 21;
                    section.data(18).dtTransOffset = 26;

                    ;% rtDW.clho1gkq3g.LoggedData
                    section.data(19).logicalSrcIdx = 22;
                    section.data(19).dtTransOffset = 28;

                    ;% rtDW.g2jykluzrf.LoggedData
                    section.data(20).logicalSrcIdx = 23;
                    section.data(20).dtTransOffset = 29;

                    ;% rtDW.onf2p44sos.LoggedData
                    section.data(21).logicalSrcIdx = 24;
                    section.data(21).dtTransOffset = 30;

                    ;% rtDW.kdzdbp0elu.LoggedData
                    section.data(22).logicalSrcIdx = 25;
                    section.data(22).dtTransOffset = 32;

                    ;% rtDW.mf4mhacv0f.LoggedData
                    section.data(23).logicalSrcIdx = 26;
                    section.data(23).dtTransOffset = 34;

                    ;% rtDW.d12nd4hp5c.LoggedData
                    section.data(24).logicalSrcIdx = 27;
                    section.data(24).dtTransOffset = 36;

                    ;% rtDW.buxg0rd2km.LoggedData
                    section.data(25).logicalSrcIdx = 28;
                    section.data(25).dtTransOffset = 38;

                    ;% rtDW.gqxpdwvbmb.LoggedData
                    section.data(26).logicalSrcIdx = 29;
                    section.data(26).dtTransOffset = 40;

                    ;% rtDW.b1yqmmv0dx.LoggedData
                    section.data(27).logicalSrcIdx = 30;
                    section.data(27).dtTransOffset = 41;

                    ;% rtDW.bxzdhrbzyg.LoggedData
                    section.data(28).logicalSrcIdx = 31;
                    section.data(28).dtTransOffset = 44;

                    ;% rtDW.oigfg0yqvv.LoggedData
                    section.data(29).logicalSrcIdx = 32;
                    section.data(29).dtTransOffset = 47;

                    ;% rtDW.ezjujxm5pa.LoggedData
                    section.data(30).logicalSrcIdx = 33;
                    section.data(30).dtTransOffset = 48;

                    ;% rtDW.ltbinp4yyk.LoggedData
                    section.data(31).logicalSrcIdx = 34;
                    section.data(31).dtTransOffset = 50;

                    ;% rtDW.ifgghblkfu.LoggedData
                    section.data(32).logicalSrcIdx = 35;
                    section.data(32).dtTransOffset = 52;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 9;
            section.data(9)  = dumData; %prealloc

                    ;% rtDW.gkxlktnf2e
                    section.data(1).logicalSrcIdx = 36;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.bk0pvczvd4
                    section.data(2).logicalSrcIdx = 37;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.cfnq23qry5
                    section.data(3).logicalSrcIdx = 38;
                    section.data(3).dtTransOffset = 2;

                    ;% rtDW.fsiptkwftx
                    section.data(4).logicalSrcIdx = 39;
                    section.data(4).dtTransOffset = 3;

                    ;% rtDW.cfwppspejc
                    section.data(5).logicalSrcIdx = 40;
                    section.data(5).dtTransOffset = 4;

                    ;% rtDW.nxdrt45sme
                    section.data(6).logicalSrcIdx = 41;
                    section.data(6).dtTransOffset = 5;

                    ;% rtDW.abzut1gmtw
                    section.data(7).logicalSrcIdx = 42;
                    section.data(7).dtTransOffset = 6;

                    ;% rtDW.moosp1s1ah
                    section.data(8).logicalSrcIdx = 43;
                    section.data(8).dtTransOffset = 7;

                    ;% rtDW.devpcih51d
                    section.data(9).logicalSrcIdx = 44;
                    section.data(9).dtTransOffset = 8;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.afdxa4jpho
                    section.data(1).logicalSrcIdx = 45;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(4) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.fjmelxecm4.PrevIndex
                    section.data(1).logicalSrcIdx = 46;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(5) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.prwdcgjlej
                    section.data(1).logicalSrcIdx = 47;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(6) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% rtDW.eohtar5htx
                    section.data(1).logicalSrcIdx = 48;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.estxwgqypi
                    section.data(2).logicalSrcIdx = 49;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(7) = section;
            clear section


            ;%
            ;% Non-auto Data (dwork)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        dworkMap.nTotData = nTotData;



    ;%
    ;% Add individual maps to base struct.
    ;%

    targMap.paramMap  = paramMap;
    targMap.signalMap = sigMap;
    targMap.dworkMap  = dworkMap;

    ;%
    ;% Add checksums to base struct.
    ;%


    targMap.checksum0 = 141128117;
    targMap.checksum1 = 3368571104;
    targMap.checksum2 = 3117770537;
    targMap.checksum3 = 2825097179;

