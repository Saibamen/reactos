/*
 * PROJECT:         ReactOS win32 subsystem
 * LICENSE:         GPL - See COPYING in the top level directory
 * PURPOSE:         DC/font related functions
 * PROGRAMMER:      Timo Kreuzer (timo.kreuzer@reactos.org)
 */

#include <win32k.h>
#include "font.h"

#define NDEBUG
#include <debug.h>

PRFONT
NTAPI
DC_prfnt(PDC pdc)
{
    PRFONT prfnt = 0;

    /* Select "current" font */
    DC_hSelectFont(pdc, pdc->pdcattr->hlfntNew);

    /* Check if font is already realized */
    if (pdc->hlfntCur != pdc->dclevel.plfnt->baseobj.hHmgr)
    {
        __debugbreak();
        //prfnt = LFONT_prfntRealizeFont(pdc->dclevel.plfnt);

        /* Dereference the old RFONT */
        //RFONT_ShareUnlockFont(pdc->prfnt);

        pdc->prfnt = prfnt;

        /* Set as new active font */
        pdc->hlfntCur = pdc->pdcattr->hlfntNew;
    }

    ASSERT(prfnt);
    return prfnt;
}

W32KAPI
BOOL
APIENTRY
NtGdiAddRemoteFontToDC(
    IN HDC hdc,
    IN PVOID pvBuffer,
    IN ULONG cjBuffer,
    IN OPTIONAL PUNIVERSAL_FONT_ID pufi)
{
    ASSERT(FALSE);
    return FALSE;
}


W32KAPI
BOOL
APIENTRY
NtGdiAddEmbFontToDC(
    IN HDC hdc,
    IN VOID **pFontID)
{
    ASSERT(FALSE);
    return FALSE;
}

W32KAPI
ULONG
APIENTRY
NtGdiGetEmbedFonts(VOID)
{
    ASSERT(FALSE);
    return FALSE;
}


W32KAPI
DWORD
APIENTRY
NtGdiGetCharSet(
    IN HDC hdc)
{
    ASSERT(FALSE);
#if 0
    PDC pdc;

    pdc = DC_LockDc(hdc);
    if (!pdc)
    {
        return -1; // FIXME ???
    }

    prfnt = DC_prfnt(pdc);

    jWinCharSet = prfnt->ppfe->pifi->jWinCharSet;


    return jWinCharSet;
#endif
return 0;
}

W32KAPI
BOOL
APIENTRY
NtGdiSetFontXform(
    IN HDC hdc,
    IN DWORD dwxScale,
    IN DWORD dwyScale)
{
    ASSERT(FALSE);
    return FALSE;
}


W32KAPI
BOOL
APIENTRY
NtGdiSetTextJustification(
    IN HDC hdc,
    IN INT lBreakExtra,
    IN INT cBreak)
{
    ASSERT(FALSE);
    return FALSE;
}

