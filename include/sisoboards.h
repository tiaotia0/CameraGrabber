/**
 * sisoboards.h
 *
 * Copyright (c) 2009,2010 Silicon Software GmbH, All Rights Reserved.
 *
 *
 * \file sisoboards.h
 *
 * \brief Board type constant definitions.
 *
 * \author Silicon Software GmbH
 */

#ifndef _SISOBOARDS_H
#define _SISOBOARDS_H

/**
 * Board type identifiers.
 *
 * Every device is identified by one of these identifiers. They
 * can be queried e.g. by Fg_getBoardType() or with
 * Fg_getParameterWithType() using the #FG_BOARD_INFORMATION argument.
 *
 * Please note that subvariants of the boards that are only different by the
 * physical layout of the connectors (e.g. CL connectors vs. PoCL connectors)
 * use the same type value.
 */
enum siso_board_type {
    PN_MICROENABLE = 0xa1,                             /**< microEnable I */
    PN_MICROENABLEII = 0xa2,                           /**< microEnable II */
    PN_MICROENABLE3I = 0xa3,                           /**< microEnable III */
    PN_MICROENABLE3IXXL = 0xa31,                       /**< microEnable III-XXL */

    PN_MICROENABLE4AD1CL = 0xa40,                      /**< microEnable IV AD1-CL */
    PN_MICROENABLE4BASE =
        PN_MICROENABLE4AD1CL,                          /**< \deprecated old name for PN_MICROENABLE4AD1CL, maintained only for source compatibility */
    PN_MICROENABLE4BASEx4 = 0xa43,                     /**< \deprecated name for a prototype never used*/
    PN_MICROENABLE4AD4CL = 0xa42,                      /**< microEnable IV AD4-CL */
    PN_MICROENABLE4VD1CL = 0xa41,                      /**< microEnable IV VD1-CL */
    PN_MICROENABLE4FULLx1 =
        PN_MICROENABLE4VD1CL,                          /**< \deprecated old name for PN_MICROENABLE4VD1CL, maintained only for source compatibility */
    PN_MICROENABLE4VD4CL = 0xa44,                      /**< microEnable IV VD4-CL */
    PN_MICROENABLE4FULLx4 =
        PN_MICROENABLE4VD4CL,                          /**< \deprecated old name for PN_MICROENABLE4VD4CL, maintained only for source compatibility */
    PN_MICROENABLE4AS1CL = 0xa45,                      /**< microEnable IV AS1-CL */
    PN_MICROENABLE4VQ4GE = 0xe44,                      /**< microEnable IV VQ4-GE */
    PN_MICROENABLE4GIGEx4 =
        PN_MICROENABLE4VQ4GE,                          /**< \deprecated old name for PN_MICROENABLE4VQ4GE, maintained only for source compatibility */
    PN_MICROENABLE4AQ4GE = 0xe42,                      /**< microEnable IV AQ4-GE */
    PN_MICROENABLE4_H264CLx1 = 0xb41,                  /**< kappa h264 Fujitsu MB86H51 */
    PN_MICROENABLE4_H264pCLx1 = 0xb42,                 /**< kappa h264 Fujitsu MB86H46A */

    PN_PX100 = 0xc41,                                  /**< PixelPlant PX100 */
    PN_PX200 = 0xc42,                                  /**< PixelPlant PX200 */
    PN_PX210 = 0xc43,                                  /**< PixelPlant PX210-CL */
    PN_PX300 = 0xc44,                                  /**< PixelPlant PX300-CxP */

    PN_MICROENABLE5A1CLHSF2 = 0xa52,                   /**< microEnable 5 A1-CLHS-F2 */
    PN_MICROENABLE5AD8CLHSF2 = 0xa55,                  /**< microEnable 5 AD8-CLHS-F2 */
    PN_MICROENABLE5A2CLHSF2 = 0xa59,                   /**< microEnable 5 A2-CLHS-F2 */
    PN_MICROENABLE5A1CXP4 = 0xa51,                     /**< microEnable 5 A01-CXP */
    PN_MICROENABLE5AQ8CXP6B = 0xa53,                   /**< microEnable 5 AQ8-CXP6B */
    PN_MICROENABLE5AQ8CXP4 =
        PN_MICROENABLE5AQ8CXP6B,                       /**< \deprecated old name for PN_MICROENABLE5AQ8CXP6B, maintained only for source compatibility */
    PN_MICROENABLE5VQ8CXP6B = 0xa54,                   /**< microEnable 5 VQ8-CXP6B */
    PN_MICROENABLE5VQ8CXP4 =
        PN_MICROENABLE5VQ8CXP6B,                       /**<\deprecated old name for PN_MICROENABLE5VQ8CXP6B, maintained only for source compatibility */
    PN_MICROENABLE5AQ8CXP6D = 0xa57,                   /**< microEnable 5 AQ8-CXP6D */
    PN_MICROENABLE5VQ8CXP6D = 0xa56,                   /**< microEnable 5 VQ8-CXP6D */
    PN_MICROENABLE5VD8CL = 0xa58,                      /**< microEnable 5 VD8-CL */
    PN_MICROENABLE5VF8CL =
        PN_MICROENABLE5VD8CL,                          /**< \deprecated old name for PN_MICROENABLE5VD8CL, maintained only for source compatibility */
    PN_MICROENABLE5AD8CL = 0xa5a,                      /**< microEnable 5 AD8-CL */

    PN_MICROENABLE5_LIGHTBRIDGE_VCL_PROTOTYPE = 0x750, /**< LightBridge VCL Prototype */
    PN_MICROENABLE5_LIGHTBRIDGE_MARATHON_VCL = 0x751,  /**< LightBridge/Marathon VCL */
    PN_MICROENABLE5_LIGHTBRIDGE_VCL = 0x7510,          /**< LightBridge VCL */
    PN_MICROENABLE5_MARATHON_VCL = 0x7511,             /**< Marathon VCL */
    PN_MICROENABLE5_MARATHON_AF2_DP = 0x752,           /**< microEnable 5 marathon AF2 DP (CLHS dual port) */
    PN_MICROENABLE5_MARATHON_VCX_QP = 0x753,           /**< microEnable 5 marathon VCX QP (CXP quad port) */

    PN_TDI = 0xb50,                                    /**< Thunderbolt Device Interface */
    PN_TTDI = 0xb5f,                                   /**< Test Thunderbolt Device Interface */

    PN_MICROENABLE5_ABACUS_4G = 0xb51,                 /**< microEnable 5 Abacus 4G */

#ifdef PLATFORM_PROTOTYPING
    PN_ML605 = 0xff46, /**< Xilinx ML605 Evaluation board */
#endif

    PN_UNKNOWN = 0xffff,
    PN_NONE = 0
};

#ifdef __cplusplus

static inline bool SisoBoardIsMe3(const int boardType)
{
    switch (boardType) {
        case PN_MICROENABLE3I:
        case PN_MICROENABLE3IXXL:
            return true;
        default:
            return false;
    }
}

static inline bool SisoBoardIsMe4(const int boardType)
{
    switch (boardType) {
        case PN_MICROENABLE4AD1CL:
        case PN_MICROENABLE4BASEx4:
        case PN_MICROENABLE4AD4CL:
        case PN_MICROENABLE4VD1CL:
        case PN_MICROENABLE4VD4CL:
        case PN_MICROENABLE4AS1CL:
        case PN_MICROENABLE4_H264CLx1:
        case PN_MICROENABLE4_H264pCLx1:
        case PN_MICROENABLE4VQ4GE:
        case PN_MICROENABLE4AQ4GE:
            return true;
        default:
            return false;
    }
}

static inline bool SisoBoardIsPxp(const int boardType)
{
    switch (boardType) {
        case PN_PX100:
        case PN_PX200:
        case PN_PX210:
        case PN_PX300:
            return true;
        default:
            return false;
    }
}

static inline bool SisoBoardIsMe5(const int boardType)
{
    switch (boardType) {
        case PN_MICROENABLE5A1CLHSF2:
        case PN_MICROENABLE5AD8CLHSF2:
        case PN_MICROENABLE5A2CLHSF2:
        case PN_MICROENABLE5A1CXP4:
        case PN_MICROENABLE5AQ8CXP6B:
        case PN_MICROENABLE5VQ8CXP6B:
        case PN_MICROENABLE5AQ8CXP6D:
        case PN_MICROENABLE5VQ8CXP6D:
        case PN_MICROENABLE5VD8CL:
        case PN_MICROENABLE5AD8CL:
        case PN_TDI:
        case PN_TTDI:
        case PN_MICROENABLE5_ABACUS_4G:
        case PN_MICROENABLE5_LIGHTBRIDGE_VCL_PROTOTYPE:
        case PN_MICROENABLE5_LIGHTBRIDGE_MARATHON_VCL:
        case PN_MICROENABLE5_LIGHTBRIDGE_VCL:
        case PN_MICROENABLE5_MARATHON_VCL:
        case PN_MICROENABLE5_MARATHON_AF2_DP:
        case PN_MICROENABLE5_MARATHON_VCX_QP:
            return true;
        default:
            return false;
    }
}

static inline bool SisoBoardIsCL(const int boardType)
{
    switch (boardType) {
        case PN_MICROENABLE4AD1CL:
        case PN_MICROENABLE4BASEx4:
        case PN_MICROENABLE4AD4CL:
        case PN_MICROENABLE4VD1CL:
        case PN_MICROENABLE4VD4CL:
        case PN_MICROENABLE4AS1CL:
        case PN_MICROENABLE5VD8CL:
        case PN_MICROENABLE5AD8CL:
        case PN_MICROENABLE5_LIGHTBRIDGE_VCL_PROTOTYPE:
        case PN_MICROENABLE5_LIGHTBRIDGE_MARATHON_VCL:
        case PN_MICROENABLE5_LIGHTBRIDGE_VCL:
        case PN_MICROENABLE5_MARATHON_VCL:
            return true;
        default:
            return false;
    }
}

static inline bool SisoBoardIsGigE(const int boardType)
{
    switch (boardType) {
        case PN_MICROENABLE4VQ4GE:
        case PN_MICROENABLE4AQ4GE:
        case PN_MICROENABLE5_ABACUS_4G:
            return true;
        default:
            return false;
    }
}

static inline bool SisoBoardIsCXP(const int boardType)
{
    switch (boardType) {
        case PN_MICROENABLE5A1CXP4:
        case PN_MICROENABLE5AQ8CXP6B:
        case PN_MICROENABLE5VQ8CXP6B:
        case PN_MICROENABLE5AQ8CXP6D:
        case PN_MICROENABLE5VQ8CXP6D:
        case PN_MICROENABLE5_MARATHON_VCX_QP:
            return true;
        default:
            return false;
    }
}

static inline bool SisoBoardIsCLHS(const int boardType)
{
    switch (boardType) {
        case PN_MICROENABLE5A1CLHSF2:
        case PN_MICROENABLE5AD8CLHSF2:
        case PN_MICROENABLE5A2CLHSF2:
        case PN_MICROENABLE5_MARATHON_AF2_DP:
            return true;
        default:
            return false;
    }
}

static inline bool SisoBoardIsOEM(const int boardType)
{
    switch (boardType) {
        case PN_TDI:
        case PN_TTDI:
        case PN_MICROENABLE5_ABACUS_4G:
            return true;
        default:
            return false;
    }
}

#endif

#endif
