/*
 * avm_kernel_config.h from AVM open-source package for 7580.06.53
 * with some symbols #ifdef'ed out to avoid their accidental usage
 */

#ifndef _STRIPPED_AVM_KERNEL_CONFIG_H_
#define _STRIPPED_AVM_KERNEL_CONFIG_H_

enum _avm_kernel_config_tags {
	avm_kernel_config_tags_undef,
	avm_kernel_config_tags_modulememory,
	avm_kernel_config_tags_version_info,
	avm_kernel_config_tags_hw_config,
	avm_kernel_config_tags_cache_config,
#if !defined(USE_STRIPPED_AVM_KERNEL_CONFIG_H)
	avm_kernel_config_tags_device_tree_subrev_0,  /* subrev müssen aufeinander folgen */
	avm_kernel_config_tags_device_tree_subrev_1,
	avm_kernel_config_tags_device_tree_subrev_2,
	avm_kernel_config_tags_device_tree_subrev_3,
	avm_kernel_config_tags_device_tree_subrev_4,
	avm_kernel_config_tags_device_tree_subrev_5,
	avm_kernel_config_tags_device_tree_subrev_6,
	avm_kernel_config_tags_device_tree_subrev_7,
	avm_kernel_config_tags_device_tree_subrev_8,
	avm_kernel_config_tags_device_tree_subrev_9,  /* subrev müssen aufeinander folgen */
	avm_kernel_config_tags_device_tree_subrev_10, /* values from 10 to 255 are available only in the version for GRX5 boxes */
	avm_kernel_config_tags_device_tree_subrev_11,
	avm_kernel_config_tags_device_tree_subrev_12,
	avm_kernel_config_tags_device_tree_subrev_13,
	avm_kernel_config_tags_device_tree_subrev_14,
	avm_kernel_config_tags_device_tree_subrev_15,
	avm_kernel_config_tags_device_tree_subrev_16,
	avm_kernel_config_tags_device_tree_subrev_17,
	avm_kernel_config_tags_device_tree_subrev_18,
	avm_kernel_config_tags_device_tree_subrev_19,
	avm_kernel_config_tags_device_tree_subrev_20,
	avm_kernel_config_tags_device_tree_subrev_21,
	avm_kernel_config_tags_device_tree_subrev_22,
	avm_kernel_config_tags_device_tree_subrev_23,
	avm_kernel_config_tags_device_tree_subrev_24,
	avm_kernel_config_tags_device_tree_subrev_25,
	avm_kernel_config_tags_device_tree_subrev_26,
	avm_kernel_config_tags_device_tree_subrev_27,
	avm_kernel_config_tags_device_tree_subrev_28,
	avm_kernel_config_tags_device_tree_subrev_29,
	avm_kernel_config_tags_device_tree_subrev_30,
	avm_kernel_config_tags_device_tree_subrev_31,
	avm_kernel_config_tags_device_tree_subrev_32,
	avm_kernel_config_tags_device_tree_subrev_33,
	avm_kernel_config_tags_device_tree_subrev_34,
	avm_kernel_config_tags_device_tree_subrev_35,
	avm_kernel_config_tags_device_tree_subrev_36,
	avm_kernel_config_tags_device_tree_subrev_37,
	avm_kernel_config_tags_device_tree_subrev_38,
	avm_kernel_config_tags_device_tree_subrev_39,
	avm_kernel_config_tags_device_tree_subrev_40,
	avm_kernel_config_tags_device_tree_subrev_41,
	avm_kernel_config_tags_device_tree_subrev_42,
	avm_kernel_config_tags_device_tree_subrev_43,
	avm_kernel_config_tags_device_tree_subrev_44,
	avm_kernel_config_tags_device_tree_subrev_45,
	avm_kernel_config_tags_device_tree_subrev_46,
	avm_kernel_config_tags_device_tree_subrev_47,
	avm_kernel_config_tags_device_tree_subrev_48,
	avm_kernel_config_tags_device_tree_subrev_49,
	avm_kernel_config_tags_device_tree_subrev_50,
	avm_kernel_config_tags_device_tree_subrev_51,
	avm_kernel_config_tags_device_tree_subrev_52,
	avm_kernel_config_tags_device_tree_subrev_53,
	avm_kernel_config_tags_device_tree_subrev_54,
	avm_kernel_config_tags_device_tree_subrev_55,
	avm_kernel_config_tags_device_tree_subrev_56,
	avm_kernel_config_tags_device_tree_subrev_57,
	avm_kernel_config_tags_device_tree_subrev_58,
	avm_kernel_config_tags_device_tree_subrev_59,
	avm_kernel_config_tags_device_tree_subrev_60,
	avm_kernel_config_tags_device_tree_subrev_61,
	avm_kernel_config_tags_device_tree_subrev_62,
	avm_kernel_config_tags_device_tree_subrev_63,
	avm_kernel_config_tags_device_tree_subrev_64,
	avm_kernel_config_tags_device_tree_subrev_65,
	avm_kernel_config_tags_device_tree_subrev_66,
	avm_kernel_config_tags_device_tree_subrev_67,
	avm_kernel_config_tags_device_tree_subrev_68,
	avm_kernel_config_tags_device_tree_subrev_69,
	avm_kernel_config_tags_device_tree_subrev_70,
	avm_kernel_config_tags_device_tree_subrev_71,
	avm_kernel_config_tags_device_tree_subrev_72,
	avm_kernel_config_tags_device_tree_subrev_73,
	avm_kernel_config_tags_device_tree_subrev_74,
	avm_kernel_config_tags_device_tree_subrev_75,
	avm_kernel_config_tags_device_tree_subrev_76,
	avm_kernel_config_tags_device_tree_subrev_77,
	avm_kernel_config_tags_device_tree_subrev_78,
	avm_kernel_config_tags_device_tree_subrev_79,
	avm_kernel_config_tags_device_tree_subrev_80,
	avm_kernel_config_tags_device_tree_subrev_81,
	avm_kernel_config_tags_device_tree_subrev_82,
	avm_kernel_config_tags_device_tree_subrev_83,
	avm_kernel_config_tags_device_tree_subrev_84,
	avm_kernel_config_tags_device_tree_subrev_85,
	avm_kernel_config_tags_device_tree_subrev_86,
	avm_kernel_config_tags_device_tree_subrev_87,
	avm_kernel_config_tags_device_tree_subrev_88,
	avm_kernel_config_tags_device_tree_subrev_89,
	avm_kernel_config_tags_device_tree_subrev_90,
	avm_kernel_config_tags_device_tree_subrev_91,
	avm_kernel_config_tags_device_tree_subrev_92,
	avm_kernel_config_tags_device_tree_subrev_93,
	avm_kernel_config_tags_device_tree_subrev_94,
	avm_kernel_config_tags_device_tree_subrev_95,
	avm_kernel_config_tags_device_tree_subrev_96,
	avm_kernel_config_tags_device_tree_subrev_97,
	avm_kernel_config_tags_device_tree_subrev_98,
	avm_kernel_config_tags_device_tree_subrev_99,
	avm_kernel_config_tags_device_tree_subrev_100,
	avm_kernel_config_tags_device_tree_subrev_101,
	avm_kernel_config_tags_device_tree_subrev_102,
	avm_kernel_config_tags_device_tree_subrev_103,
	avm_kernel_config_tags_device_tree_subrev_104,
	avm_kernel_config_tags_device_tree_subrev_105,
	avm_kernel_config_tags_device_tree_subrev_106,
	avm_kernel_config_tags_device_tree_subrev_107,
	avm_kernel_config_tags_device_tree_subrev_108,
	avm_kernel_config_tags_device_tree_subrev_109,
	avm_kernel_config_tags_device_tree_subrev_110,
	avm_kernel_config_tags_device_tree_subrev_111,
	avm_kernel_config_tags_device_tree_subrev_112,
	avm_kernel_config_tags_device_tree_subrev_113,
	avm_kernel_config_tags_device_tree_subrev_114,
	avm_kernel_config_tags_device_tree_subrev_115,
	avm_kernel_config_tags_device_tree_subrev_116,
	avm_kernel_config_tags_device_tree_subrev_117,
	avm_kernel_config_tags_device_tree_subrev_118,
	avm_kernel_config_tags_device_tree_subrev_119,
	avm_kernel_config_tags_device_tree_subrev_120,
	avm_kernel_config_tags_device_tree_subrev_121,
	avm_kernel_config_tags_device_tree_subrev_122,
	avm_kernel_config_tags_device_tree_subrev_123,
	avm_kernel_config_tags_device_tree_subrev_124,
	avm_kernel_config_tags_device_tree_subrev_125,
	avm_kernel_config_tags_device_tree_subrev_126,
	avm_kernel_config_tags_device_tree_subrev_127,
	avm_kernel_config_tags_device_tree_subrev_128,
	avm_kernel_config_tags_device_tree_subrev_129,
	avm_kernel_config_tags_device_tree_subrev_130,
	avm_kernel_config_tags_device_tree_subrev_131,
	avm_kernel_config_tags_device_tree_subrev_132,
	avm_kernel_config_tags_device_tree_subrev_133,
	avm_kernel_config_tags_device_tree_subrev_134,
	avm_kernel_config_tags_device_tree_subrev_135,
	avm_kernel_config_tags_device_tree_subrev_136,
	avm_kernel_config_tags_device_tree_subrev_137,
	avm_kernel_config_tags_device_tree_subrev_138,
	avm_kernel_config_tags_device_tree_subrev_139,
	avm_kernel_config_tags_device_tree_subrev_140,
	avm_kernel_config_tags_device_tree_subrev_141,
	avm_kernel_config_tags_device_tree_subrev_142,
	avm_kernel_config_tags_device_tree_subrev_143,
	avm_kernel_config_tags_device_tree_subrev_144,
	avm_kernel_config_tags_device_tree_subrev_145,
	avm_kernel_config_tags_device_tree_subrev_146,
	avm_kernel_config_tags_device_tree_subrev_147,
	avm_kernel_config_tags_device_tree_subrev_148,
	avm_kernel_config_tags_device_tree_subrev_149,
	avm_kernel_config_tags_device_tree_subrev_150,
	avm_kernel_config_tags_device_tree_subrev_151,
	avm_kernel_config_tags_device_tree_subrev_152,
	avm_kernel_config_tags_device_tree_subrev_153,
	avm_kernel_config_tags_device_tree_subrev_154,
	avm_kernel_config_tags_device_tree_subrev_155,
	avm_kernel_config_tags_device_tree_subrev_156,
	avm_kernel_config_tags_device_tree_subrev_157,
	avm_kernel_config_tags_device_tree_subrev_158,
	avm_kernel_config_tags_device_tree_subrev_159,
	avm_kernel_config_tags_device_tree_subrev_160,
	avm_kernel_config_tags_device_tree_subrev_161,
	avm_kernel_config_tags_device_tree_subrev_162,
	avm_kernel_config_tags_device_tree_subrev_163,
	avm_kernel_config_tags_device_tree_subrev_164,
	avm_kernel_config_tags_device_tree_subrev_165,
	avm_kernel_config_tags_device_tree_subrev_166,
	avm_kernel_config_tags_device_tree_subrev_167,
	avm_kernel_config_tags_device_tree_subrev_168,
	avm_kernel_config_tags_device_tree_subrev_169,
	avm_kernel_config_tags_device_tree_subrev_170,
	avm_kernel_config_tags_device_tree_subrev_171,
	avm_kernel_config_tags_device_tree_subrev_172,
	avm_kernel_config_tags_device_tree_subrev_173,
	avm_kernel_config_tags_device_tree_subrev_174,
	avm_kernel_config_tags_device_tree_subrev_175,
	avm_kernel_config_tags_device_tree_subrev_176,
	avm_kernel_config_tags_device_tree_subrev_177,
	avm_kernel_config_tags_device_tree_subrev_178,
	avm_kernel_config_tags_device_tree_subrev_179,
	avm_kernel_config_tags_device_tree_subrev_180,
	avm_kernel_config_tags_device_tree_subrev_181,
	avm_kernel_config_tags_device_tree_subrev_182,
	avm_kernel_config_tags_device_tree_subrev_183,
	avm_kernel_config_tags_device_tree_subrev_184,
	avm_kernel_config_tags_device_tree_subrev_185,
	avm_kernel_config_tags_device_tree_subrev_186,
	avm_kernel_config_tags_device_tree_subrev_187,
	avm_kernel_config_tags_device_tree_subrev_188,
	avm_kernel_config_tags_device_tree_subrev_189,
	avm_kernel_config_tags_device_tree_subrev_190,
	avm_kernel_config_tags_device_tree_subrev_191,
	avm_kernel_config_tags_device_tree_subrev_192,
	avm_kernel_config_tags_device_tree_subrev_193,
	avm_kernel_config_tags_device_tree_subrev_194,
	avm_kernel_config_tags_device_tree_subrev_195,
	avm_kernel_config_tags_device_tree_subrev_196,
	avm_kernel_config_tags_device_tree_subrev_197,
	avm_kernel_config_tags_device_tree_subrev_198,
	avm_kernel_config_tags_device_tree_subrev_199,
	avm_kernel_config_tags_device_tree_subrev_200,
	avm_kernel_config_tags_device_tree_subrev_201,
	avm_kernel_config_tags_device_tree_subrev_202,
	avm_kernel_config_tags_device_tree_subrev_203,
	avm_kernel_config_tags_device_tree_subrev_204,
	avm_kernel_config_tags_device_tree_subrev_205,
	avm_kernel_config_tags_device_tree_subrev_206,
	avm_kernel_config_tags_device_tree_subrev_207,
	avm_kernel_config_tags_device_tree_subrev_208,
	avm_kernel_config_tags_device_tree_subrev_209,
	avm_kernel_config_tags_device_tree_subrev_210,
	avm_kernel_config_tags_device_tree_subrev_211,
	avm_kernel_config_tags_device_tree_subrev_212,
	avm_kernel_config_tags_device_tree_subrev_213,
	avm_kernel_config_tags_device_tree_subrev_214,
	avm_kernel_config_tags_device_tree_subrev_215,
	avm_kernel_config_tags_device_tree_subrev_216,
	avm_kernel_config_tags_device_tree_subrev_217,
	avm_kernel_config_tags_device_tree_subrev_218,
	avm_kernel_config_tags_device_tree_subrev_219,
	avm_kernel_config_tags_device_tree_subrev_220,
	avm_kernel_config_tags_device_tree_subrev_221,
	avm_kernel_config_tags_device_tree_subrev_222,
	avm_kernel_config_tags_device_tree_subrev_223,
	avm_kernel_config_tags_device_tree_subrev_224,
	avm_kernel_config_tags_device_tree_subrev_225,
	avm_kernel_config_tags_device_tree_subrev_226,
	avm_kernel_config_tags_device_tree_subrev_227,
	avm_kernel_config_tags_device_tree_subrev_228,
	avm_kernel_config_tags_device_tree_subrev_229,
	avm_kernel_config_tags_device_tree_subrev_230,
	avm_kernel_config_tags_device_tree_subrev_231,
	avm_kernel_config_tags_device_tree_subrev_232,
	avm_kernel_config_tags_device_tree_subrev_233,
	avm_kernel_config_tags_device_tree_subrev_234,
	avm_kernel_config_tags_device_tree_subrev_235,
	avm_kernel_config_tags_device_tree_subrev_236,
	avm_kernel_config_tags_device_tree_subrev_237,
	avm_kernel_config_tags_device_tree_subrev_238,
	avm_kernel_config_tags_device_tree_subrev_239,
	avm_kernel_config_tags_device_tree_subrev_240,
	avm_kernel_config_tags_device_tree_subrev_241,
	avm_kernel_config_tags_device_tree_subrev_242,
	avm_kernel_config_tags_device_tree_subrev_243,
	avm_kernel_config_tags_device_tree_subrev_244,
	avm_kernel_config_tags_device_tree_subrev_245,
	avm_kernel_config_tags_device_tree_subrev_246,
	avm_kernel_config_tags_device_tree_subrev_247,
	avm_kernel_config_tags_device_tree_subrev_248,
	avm_kernel_config_tags_device_tree_subrev_249,
	avm_kernel_config_tags_device_tree_subrev_250,
	avm_kernel_config_tags_device_tree_subrev_251,
	avm_kernel_config_tags_device_tree_subrev_252,
	avm_kernel_config_tags_device_tree_subrev_253,
	avm_kernel_config_tags_device_tree_subrev_254,
	avm_kernel_config_tags_device_tree_subrev_255,
	avm_kernel_config_tags_device_tree_subrev_last = avm_kernel_config_tags_device_tree_subrev_255,
	avm_kernel_config_tags_avmnet,
	avm_kernel_config_tags_last
#endif
};

#if !defined(USE_STRIPPED_AVM_KERNEL_CONFIG_H)
#define avm_subrev_max \
	(avm_kernel_config_tags_device_tree_subrev_last - \
	 avm_kernel_config_tags_device_tree_subrev_0 + 1)
#endif

struct _kernel_modulmemory_config {
	char *name;
	unsigned int size;
};

struct _avm_kernel_config {
	enum _avm_kernel_config_tags tag;
	void *config;
};

struct _avm_kernel_version_info {
	char buildnumber[32];
	char svnversion[32];
	char firmwarestring[128];
};

#if !defined(USE_STRIPPED_AVM_KERNEL_CONFIG_H)
extern unsigned char *avm_kernel_config_device_tree[avm_kernel_config_tags_device_tree_subrev_last - avm_kernel_config_tags_device_tree_subrev_0 + 1];
#endif

#endif
