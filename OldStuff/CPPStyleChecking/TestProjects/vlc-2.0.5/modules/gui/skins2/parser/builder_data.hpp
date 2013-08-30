/*****************************************************************************
 * builder_data.hpp
 *****************************************************************************
 * Copyright (C) 2003 the VideoLAN team
 * $Id: a14bdf52cd308fe234a07001695f56e9a8980fab $
 *
 * Authors: Cyril Deguet     <asmax@via.ecp.fr>
 *          Olivier Teuliere <ipkiss@via.ecp.fr>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/

//File generated by gen_builder.py
//DO NOT EDIT BY HAND !

#ifndef BUILDER_DATA_HPP
#define BUILDER_DATA_HPP

#include <vlc_common.h>
#include <list>
#include <map>
#include <string>

using namespace std;

/// Structure for mapping data from XML file
struct BuilderData
{

    /// Type definition
    struct Theme
    {
        Theme( const string & tooltipfont, int magnet, uint32_t alpha, uint32_t moveAlpha ):
m_tooltipfont( tooltipfont ), m_magnet( magnet ), m_alpha( alpha ), m_moveAlpha( moveAlpha ) {}

        string m_tooltipfont;
        int m_magnet;
        uint32_t m_alpha;
        uint32_t m_moveAlpha;
    };
    /// List
    list<Theme> m_listTheme;

    /// Type definition
    struct Bitmap
    {
        Bitmap( const string & id, const string & fileName, uint32_t alphaColor, int nbFrames, int fps, int nbLoops ):
m_id( id ), m_fileName( fileName ), m_alphaColor( alphaColor ), m_nbFrames( nbFrames ), m_fps( fps ), m_nbLoops( nbLoops ) {}

        string m_id;
        string m_fileName;
        uint32_t m_alphaColor;
        int m_nbFrames;
        int m_fps;
        int m_nbLoops;
    };
    /// List
    list<Bitmap> m_listBitmap;

    /// Type definition
    struct SubBitmap
    {
        SubBitmap( const string & id, const string & parent, int x, int y, int width, int height, int nbFrames, int fps, int nbLoops ):
m_id( id ), m_parent( parent ), m_x( x ), m_y( y ), m_width( width ), m_height( height ), m_nbFrames( nbFrames ), m_fps( fps ), m_nbLoops( nbLoops ) {}

        string m_id;
        string m_parent;
        int m_x;
        int m_y;
        int m_width;
        int m_height;
        int m_nbFrames;
        int m_fps;
        int m_nbLoops;
    };
    /// List
    list<SubBitmap> m_listSubBitmap;

    /// Type definition
    struct BitmapFont
    {
        BitmapFont( const string & id, const string & file, const string & type ):
m_id( id ), m_file( file ), m_type( type ) {}

        string m_id;
        string m_file;
        string m_type;
    };
    /// List
    list<BitmapFont> m_listBitmapFont;

    /// Type definition
    struct Font
    {
        Font( const string & id, const string & fontFile, int size ):
m_id( id ), m_fontFile( fontFile ), m_size( size ) {}

        string m_id;
        string m_fontFile;
        int m_size;
    };
    /// List
    list<Font> m_listFont;

    /// Type definition
    struct PopupMenu
    {
        PopupMenu( const string & id ):
m_id( id ) {}

        string m_id;
    };
    /// List
    list<PopupMenu> m_listPopupMenu;

    /// Type definition
    struct MenuItem
    {
        MenuItem( const string & label, const string & action, int pos, const string & popupId ):
m_label( label ), m_action( action ), m_pos( pos ), m_popupId( popupId ) {}

        string m_label;
        string m_action;
        int m_pos;
        string m_popupId;
    };
    /// List
    list<MenuItem> m_listMenuItem;

    /// Type definition
    struct MenuSeparator
    {
        MenuSeparator( int pos, const string & popupId ):
m_pos( pos ), m_popupId( popupId ) {}

        int m_pos;
        string m_popupId;
    };
    /// List
    list<MenuSeparator> m_listMenuSeparator;

    /// Type definition
    struct Window
    {
        Window( const string & id, int xPos, int yPos, const string & position, const string & xOffset, const string & yOffset, const string & xMargin, const string & yMargin, bool visible, bool dragDrop, bool playOnDrop ):
m_id( id ), m_xPos( xPos ), m_yPos( yPos ), m_position( position ), m_xOffset( xOffset ), m_yOffset( yOffset ), m_xMargin( xMargin ), m_yMargin( yMargin ), m_visible( visible ), m_dragDrop( dragDrop ), m_playOnDrop( playOnDrop ) {}

        string m_id;
        int m_xPos;
        int m_yPos;
        string m_position;
        string m_xOffset;
        string m_yOffset;
        string m_xMargin;
        string m_yMargin;
        bool m_visible;
        bool m_dragDrop;
        bool m_playOnDrop;
    };
    /// List
    list<Window> m_listWindow;

    /// Type definition
    struct Layout
    {
        Layout( const string & id, int width, int height, int minWidth, int maxWidth, int minHeight, int maxHeight, const string & windowId ):
m_id( id ), m_width( width ), m_height( height ), m_minWidth( minWidth ), m_maxWidth( maxWidth ), m_minHeight( minHeight ), m_maxHeight( maxHeight ), m_windowId( windowId ) {}

        string m_id;
        int m_width;
        int m_height;
        int m_minWidth;
        int m_maxWidth;
        int m_minHeight;
        int m_maxHeight;
        string m_windowId;
    };
    /// List
    list<Layout> m_listLayout;

    /// Type definition
    struct Anchor
    {
        Anchor( int xPos, int yPos, const string & leftTop, int range, int priority, const string & points, const string & layoutId ):
m_xPos( xPos ), m_yPos( yPos ), m_leftTop( leftTop ), m_range( range ), m_priority( priority ), m_points( points ), m_layoutId( layoutId ) {}

        int m_xPos;
        int m_yPos;
        string m_leftTop;
        int m_range;
        int m_priority;
        string m_points;
        string m_layoutId;
    };
    /// List
    list<Anchor> m_listAnchor;

    /// Type definition
    struct Button
    {
        Button( const string & id, int xPos, int yPos, const string & leftTop, const string & rightBottom, bool xKeepRatio, bool yKeepRatio, const string & visible, const string & upId, const string & downId, const string & overId, const string & actionId, const string & tooltip, const string & help, int layer, const string & windowId, const string & layoutId, const string & panelId ):
m_id( id ), m_xPos( xPos ), m_yPos( yPos ), m_leftTop( leftTop ), m_rightBottom( rightBottom ), m_xKeepRatio( xKeepRatio ), m_yKeepRatio( yKeepRatio ), m_visible( visible ), m_upId( upId ), m_downId( downId ), m_overId( overId ), m_actionId( actionId ), m_tooltip( tooltip ), m_help( help ), m_layer( layer ), m_windowId( windowId ), m_layoutId( layoutId ), m_panelId( panelId ) {}

        string m_id;
        int m_xPos;
        int m_yPos;
        string m_leftTop;
        string m_rightBottom;
        bool m_xKeepRatio;
        bool m_yKeepRatio;
        string m_visible;
        string m_upId;
        string m_downId;
        string m_overId;
        string m_actionId;
        string m_tooltip;
        string m_help;
        int m_layer;
        string m_windowId;
        string m_layoutId;
        string m_panelId;
    };
    /// List
    list<Button> m_listButton;

    /// Type definition
    struct Checkbox
    {
        Checkbox( const string & id, int xPos, int yPos, const string & leftTop, const string & rightBottom, bool xKeepRatio, bool yKeepRatio, const string & visible, const string & up1Id, const string & down1Id, const string & over1Id, const string & up2Id, const string & down2Id, const string & over2Id, const string & state, const string & action1, const string & action2, const string & tooltip1, const string & tooltip2, const string & help, int layer, const string & windowId, const string & layoutId, const string & panelId ):
m_id( id ), m_xPos( xPos ), m_yPos( yPos ), m_leftTop( leftTop ), m_rightBottom( rightBottom ), m_xKeepRatio( xKeepRatio ), m_yKeepRatio( yKeepRatio ), m_visible( visible ), m_up1Id( up1Id ), m_down1Id( down1Id ), m_over1Id( over1Id ), m_up2Id( up2Id ), m_down2Id( down2Id ), m_over2Id( over2Id ), m_state( state ), m_action1( action1 ), m_action2( action2 ), m_tooltip1( tooltip1 ), m_tooltip2( tooltip2 ), m_help( help ), m_layer( layer ), m_windowId( windowId ), m_layoutId( layoutId ), m_panelId( panelId ) {}

        string m_id;
        int m_xPos;
        int m_yPos;
        string m_leftTop;
        string m_rightBottom;
        bool m_xKeepRatio;
        bool m_yKeepRatio;
        string m_visible;
        string m_up1Id;
        string m_down1Id;
        string m_over1Id;
        string m_up2Id;
        string m_down2Id;
        string m_over2Id;
        string m_state;
        string m_action1;
        string m_action2;
        string m_tooltip1;
        string m_tooltip2;
        string m_help;
        int m_layer;
        string m_windowId;
        string m_layoutId;
        string m_panelId;
    };
    /// List
    list<Checkbox> m_listCheckbox;

    /// Type definition
    struct Image
    {
        Image( const string & id, int xPos, int yPos, int width, int height, const string & leftTop, const string & rightBottom, bool xKeepRatio, bool yKeepRatio, const string & visible, const string & bmpId, const string & actionId, const string & action2Id, const string & resize, const string & help, bool art, int layer, const string & windowId, const string & layoutId, const string & panelId ):
m_id( id ), m_xPos( xPos ), m_yPos( yPos ), m_width( width ), m_height( height ), m_leftTop( leftTop ), m_rightBottom( rightBottom ), m_xKeepRatio( xKeepRatio ), m_yKeepRatio( yKeepRatio ), m_visible( visible ), m_bmpId( bmpId ), m_actionId( actionId ), m_action2Id( action2Id ), m_resize( resize ), m_help( help ), m_art( art ), m_layer( layer ), m_windowId( windowId ), m_layoutId( layoutId ), m_panelId( panelId ) {}

        string m_id;
        int m_xPos;
        int m_yPos;
        int m_width;
        int m_height;
        string m_leftTop;
        string m_rightBottom;
        bool m_xKeepRatio;
        bool m_yKeepRatio;
        string m_visible;
        string m_bmpId;
        string m_actionId;
        string m_action2Id;
        string m_resize;
        string m_help;
        bool m_art;
        int m_layer;
        string m_windowId;
        string m_layoutId;
        string m_panelId;
    };
    /// List
    list<Image> m_listImage;

    /// Type definition
    struct IniFile
    {
        IniFile( const string & id, const string & file ):
m_id( id ), m_file( file ) {}

        string m_id;
        string m_file;
    };
    /// List
    list<IniFile> m_listIniFile;

    /// Type definition
    struct Panel
    {
        Panel( const string & id, int xPos, int yPos, const string & leftTop, const string & rightBottom, bool xKeepRatio, bool yKeepRatio, int width, int height, int layer, const string & windowId, const string & layoutId, const string & panelId ):
m_id( id ), m_xPos( xPos ), m_yPos( yPos ), m_leftTop( leftTop ), m_rightBottom( rightBottom ), m_xKeepRatio( xKeepRatio ), m_yKeepRatio( yKeepRatio ), m_width( width ), m_height( height ), m_layer( layer ), m_windowId( windowId ), m_layoutId( layoutId ), m_panelId( panelId ) {}

        string m_id;
        int m_xPos;
        int m_yPos;
        string m_leftTop;
        string m_rightBottom;
        bool m_xKeepRatio;
        bool m_yKeepRatio;
        int m_width;
        int m_height;
        int m_layer;
        string m_windowId;
        string m_layoutId;
        string m_panelId;
    };
    /// List
    list<Panel> m_listPanel;

    /// Type definition
    struct Text
    {
        Text( const string & id, int xPos, int yPos, const string & visible, const string & fontId, const string & text, int width, const string & leftTop, const string & rightBottom, bool xKeepRatio, bool yKeepRatio, uint32_t color, const string & scrolling, const string & alignment, const string & focus, const string & help, int layer, const string & windowId, const string & layoutId, const string & panelId ):
m_id( id ), m_xPos( xPos ), m_yPos( yPos ), m_visible( visible ), m_fontId( fontId ), m_text( text ), m_width( width ), m_leftTop( leftTop ), m_rightBottom( rightBottom ), m_xKeepRatio( xKeepRatio ), m_yKeepRatio( yKeepRatio ), m_color( color ), m_scrolling( scrolling ), m_alignment( alignment ), m_focus( focus ), m_help( help ), m_layer( layer ), m_windowId( windowId ), m_layoutId( layoutId ), m_panelId( panelId ) {}

        string m_id;
        int m_xPos;
        int m_yPos;
        string m_visible;
        string m_fontId;
        string m_text;
        int m_width;
        string m_leftTop;
        string m_rightBottom;
        bool m_xKeepRatio;
        bool m_yKeepRatio;
        uint32_t m_color;
        string m_scrolling;
        string m_alignment;
        string m_focus;
        string m_help;
        int m_layer;
        string m_windowId;
        string m_layoutId;
        string m_panelId;
    };
    /// List
    list<Text> m_listText;

    /// Type definition
    struct RadialSlider
    {
        RadialSlider( const string & id, const string & visible, int xPos, int yPos, const string & leftTop, const string & rightBottom, bool xKeepRatio, bool yKeepRatio, const string & sequence, int nbImages, float minAngle, float maxAngle, const string & value, const string & tooltip, const string & help, int layer, const string & windowId, const string & layoutId, const string & panelId ):
m_id( id ), m_visible( visible ), m_xPos( xPos ), m_yPos( yPos ), m_leftTop( leftTop ), m_rightBottom( rightBottom ), m_xKeepRatio( xKeepRatio ), m_yKeepRatio( yKeepRatio ), m_sequence( sequence ), m_nbImages( nbImages ), m_minAngle( minAngle ), m_maxAngle( maxAngle ), m_value( value ), m_tooltip( tooltip ), m_help( help ), m_layer( layer ), m_windowId( windowId ), m_layoutId( layoutId ), m_panelId( panelId ) {}

        string m_id;
        string m_visible;
        int m_xPos;
        int m_yPos;
        string m_leftTop;
        string m_rightBottom;
        bool m_xKeepRatio;
        bool m_yKeepRatio;
        string m_sequence;
        int m_nbImages;
        float m_minAngle;
        float m_maxAngle;
        string m_value;
        string m_tooltip;
        string m_help;
        int m_layer;
        string m_windowId;
        string m_layoutId;
        string m_panelId;
    };
    /// List
    list<RadialSlider> m_listRadialSlider;

    /// Type definition
    struct Slider
    {
        Slider( const string & id, const string & visible, int xPos, int yPos, const string & leftTop, const string & rightBottom, bool xKeepRatio, bool yKeepRatio, const string & upId, const string & downId, const string & overId, const string & points, int thickness, const string & value, const string & imageId, int nbHoriz, int nbVert, int padHoriz, int padVert, const string & tooltip, const string & help, int layer, const string & windowId, const string & layoutId, const string & panelId ):
m_id( id ), m_visible( visible ), m_xPos( xPos ), m_yPos( yPos ), m_leftTop( leftTop ), m_rightBottom( rightBottom ), m_xKeepRatio( xKeepRatio ), m_yKeepRatio( yKeepRatio ), m_upId( upId ), m_downId( downId ), m_overId( overId ), m_points( points ), m_thickness( thickness ), m_value( value ), m_imageId( imageId ), m_nbHoriz( nbHoriz ), m_nbVert( nbVert ), m_padHoriz( padHoriz ), m_padVert( padVert ), m_tooltip( tooltip ), m_help( help ), m_layer( layer ), m_windowId( windowId ), m_layoutId( layoutId ), m_panelId( panelId ) {}

        string m_id;
        string m_visible;
        int m_xPos;
        int m_yPos;
        string m_leftTop;
        string m_rightBottom;
        bool m_xKeepRatio;
        bool m_yKeepRatio;
        string m_upId;
        string m_downId;
        string m_overId;
        string m_points;
        int m_thickness;
        string m_value;
        string m_imageId;
        int m_nbHoriz;
        int m_nbVert;
        int m_padHoriz;
        int m_padVert;
        string m_tooltip;
        string m_help;
        int m_layer;
        string m_windowId;
        string m_layoutId;
        string m_panelId;
    };
    /// List
    list<Slider> m_listSlider;

    /// Type definition
    struct List
    {
        List( const string & id, int xPos, int yPos, const string & visible, int width, int height, const string & leftTop, const string & rightBottom, bool xKeepRatio, bool yKeepRatio, const string & fontId, const string & var, const string & bgImageId, const string & fgColor, const string & playColor, const string & bgColor1, const string & bgColor2, const string & selColor, const string & help, int layer, const string & windowId, const string & layoutId, const string & panelId ):
m_id( id ), m_xPos( xPos ), m_yPos( yPos ), m_visible( visible ), m_width( width ), m_height( height ), m_leftTop( leftTop ), m_rightBottom( rightBottom ), m_xKeepRatio( xKeepRatio ), m_yKeepRatio( yKeepRatio ), m_fontId( fontId ), m_var( var ), m_bgImageId( bgImageId ), m_fgColor( fgColor ), m_playColor( playColor ), m_bgColor1( bgColor1 ), m_bgColor2( bgColor2 ), m_selColor( selColor ), m_help( help ), m_layer( layer ), m_windowId( windowId ), m_layoutId( layoutId ), m_panelId( panelId ) {}

        string m_id;
        int m_xPos;
        int m_yPos;
        string m_visible;
        int m_width;
        int m_height;
        string m_leftTop;
        string m_rightBottom;
        bool m_xKeepRatio;
        bool m_yKeepRatio;
        string m_fontId;
        string m_var;
        string m_bgImageId;
        string m_fgColor;
        string m_playColor;
        string m_bgColor1;
        string m_bgColor2;
        string m_selColor;
        string m_help;
        int m_layer;
        string m_windowId;
        string m_layoutId;
        string m_panelId;
    };
    /// List
    list<List> m_listList;

    /// Type definition
    struct Tree
    {
        Tree( const string & id, int xPos, int yPos, const string & visible, const string & flat, int width, int height, const string & leftTop, const string & rightBottom, bool xKeepRatio, bool yKeepRatio, const string & fontId, const string & var, const string & bgImageId, const string & itemImageId, const string & openImageId, const string & closedImageId, const string & fgColor, const string & playColor, const string & bgColor1, const string & bgColor2, const string & selColor, const string & help, int layer, const string & windowId, const string & layoutId, const string & panelId ):
m_id( id ), m_xPos( xPos ), m_yPos( yPos ), m_visible( visible ), m_flat( flat ), m_width( width ), m_height( height ), m_leftTop( leftTop ), m_rightBottom( rightBottom ), m_xKeepRatio( xKeepRatio ), m_yKeepRatio( yKeepRatio ), m_fontId( fontId ), m_var( var ), m_bgImageId( bgImageId ), m_itemImageId( itemImageId ), m_openImageId( openImageId ), m_closedImageId( closedImageId ), m_fgColor( fgColor ), m_playColor( playColor ), m_bgColor1( bgColor1 ), m_bgColor2( bgColor2 ), m_selColor( selColor ), m_help( help ), m_layer( layer ), m_windowId( windowId ), m_layoutId( layoutId ), m_panelId( panelId ) {}

        string m_id;
        int m_xPos;
        int m_yPos;
        string m_visible;
        string m_flat;
        int m_width;
        int m_height;
        string m_leftTop;
        string m_rightBottom;
        bool m_xKeepRatio;
        bool m_yKeepRatio;
        string m_fontId;
        string m_var;
        string m_bgImageId;
        string m_itemImageId;
        string m_openImageId;
        string m_closedImageId;
        string m_fgColor;
        string m_playColor;
        string m_bgColor1;
        string m_bgColor2;
        string m_selColor;
        string m_help;
        int m_layer;
        string m_windowId;
        string m_layoutId;
        string m_panelId;
    };
    /// List
    list<Tree> m_listTree;

    /// Type definition
    struct Video
    {
        Video( const string & id, int xPos, int yPos, int width, int height, const string & leftTop, const string & rightBottom, bool xKeepRatio, bool yKeepRatio, const string & visible, bool autoResize, const string & help, int layer, const string & windowId, const string & layoutId, const string & panelId ):
m_id( id ), m_xPos( xPos ), m_yPos( yPos ), m_width( width ), m_height( height ), m_leftTop( leftTop ), m_rightBottom( rightBottom ), m_xKeepRatio( xKeepRatio ), m_yKeepRatio( yKeepRatio ), m_visible( visible ), m_autoResize( autoResize ), m_help( help ), m_layer( layer ), m_windowId( windowId ), m_layoutId( layoutId ), m_panelId( panelId ) {}

        string m_id;
        int m_xPos;
        int m_yPos;
        int m_width;
        int m_height;
        string m_leftTop;
        string m_rightBottom;
        bool m_xKeepRatio;
        bool m_yKeepRatio;
        string m_visible;
        bool m_autoResize;
        string m_help;
        int m_layer;
        string m_windowId;
        string m_layoutId;
        string m_panelId;
    };
    /// List
    list<Video> m_listVideo;


};

#endif
