//
//   textReader.app -  kludged up by Jim Beesley
//   This incorporates inspiration, code, and examples from (among others)
//   * The iPhone Dev Team for toolchain and more!
//   * James Yopp for the UIOrientingApplication example
//   * Paul J. Lucas for txt2pdbdoc
//   * http://iphonedevdoc.com/index.php - random hints and examples
//   * mxweas - UITransitionView example
//   * thebends.org - textDrawing example
//   * Books.app - written by Zachary Brewster-Geisz (and others)
//   * "iPhone Open Application Development" by Jonathan Zdziarski - FileTable/UIDeletableCell example
//   * http://garcya.us/ - for application icons
//   * Allen Li for help with rotation lock and swipe/gestures
//
//   This program is free software; you can redistribute it and/or
//   modify it under the terms of the GNU General Public License
//   as published by the Free Software Foundation; version 2
//   of the License.
//
//   This program is distributed in the hope that it will be useful,
//   but WITHOUT ANY WARRANTY; without even the implied warranty of
//   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//   GNU General Public License for more details.
//
//   You should have received a copy of the GNU General Public License
//   along with this program; if not, write to the Free Software
//   Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
//


#import <UIKit/UIKit.h>
#import <UIKit/UIPreferencesTable.h>
#import <UIKit/UIPreferencesTextTableCell.h>
#import <UIKit/UISwitchControl.h>
#import <UIKit/UISegmentedControl.h>
//#import <UIKit/UISlider.h>
#import <UIKit/UIPickerView.h>
#import <UIKit/UIPickerTable.h>
#import <UIKit/UIPickerTableCell.h>



// These are the MAX values - preferencesTable controls the actual number
#define NUM_GROUPS      9
#define CELLS_PER_GROUP 9



@class textReader;
@class MyTextView;
@class MyPreferencesTable;


typedef enum _PickerType {
    kPicker_Type_None              = 0,
    kPicker_Type_Font              = 1,
    kPicker_Type_FontSize          = 2,
    kPicker_Type_TextAlignment     = 3,
    kPicker_Type_IndentParagraphs  = 4,
    kPicker_Type_BkgImage          = 5,

    kPicker_Type_Encoding          = 6,
    kPicker_Type_Encoding2         = 7,
    kPicker_Type_Encoding3         = 8,
    kPicker_Type_Encoding4         = 9

} PickerType;

// **********************************************************************
// Class for Picker
@interface MyPickerView: UIPickerView{

    MyPreferencesTable *prefsTable;

    NSMutableArray     *dataArray;

    PickerType          type;

} // MyPickerView

-(BOOL)table:(UIPickerTable*)table canSelectRow:(int)row;

-(void) setType:(PickerType)theType;
-(PickerType) getType;
-(void) setPrefs:(MyPreferencesTable*)prefs;
-(NSMutableArray*) getDataArray;

@end


// **********************************************************************
// Class for Preferences Page
@interface MyPreferencesTable : UIPreferencesTable
{
    UIPreferencesTableCell *cells[NUM_GROUPS][CELLS_PER_GROUP];
    UIPreferencesTableCell *groupcell[NUM_GROUPS];


    UIPreferencesTableCell *textSettings;
    UIPreferencesTableCell *displaySettings;
    UIPreferencesTableCell *scrollSettings;
    UIPreferencesTableCell *otherSettings;


    UISwitchControl    *invertScreen;
    UISwitchControl    *padMargins;
    UISwitchControl    *reverseTap;
    UISwitchControl    *repeatLine;
    UISwitchControl    *swipeOK;
    UISwitchControl    *showCoverArt;
    UISwitchControl    *fontZoom;
    UISwitchControl    *cacheAll;
    UISwitchControl    *deleteCacheDir;
    UISwitchControl    *searchWrap;
    UISwitchControl    *searchWord;
    UISwitchControl    *rememberURL;

    textReader         *trApp;
    MyTextView         *textView;

    MyPickerView       *pickerView;

    UIPreferencesTableCell *fontCell;
    UIPreferencesTableCell *fontSizeCell;
    UIPreferencesTableCell *encodingCell;
    UIPreferencesTableCell *encoding2Cell;
    UIPreferencesTableCell *encoding3Cell;
    UIPreferencesTableCell *encoding4Cell;
    UIPreferencesTableCell *colorsCell;
    UIPreferencesTableCell *textAlignmentCell;
    UIPreferencesTableCell *bkgImageCell;
    UIPreferencesTableCell *indentParagraphsCell;

    UISegmentedControl     *ignoreSingleLF;
    UISegmentedControl     *showStatus;
    UISegmentedControl     *volumeScroll;
    UISegmentedControl     *fileScroll;

} // MyPreferencesTable


- (id)initWithFrame:(CGRect)rect trApp:(textReader*)tr;

- (int)numberOfGroupsInPreferencesTable:(UIPreferencesTable *)aTable;
- (UIPreferencesTableCell *)preferencesTable: (UIPreferencesTable *)aTable
    cellForGroup:(int)group;
- (float)preferencesTable:(UIPreferencesTable *)aTable
    heightForRow:(int)row inGroup:(int)group withProposedHeight:(float)proposed;
- (BOOL)preferencesTable:(UIPreferencesTable *)aTable isLabelGroup:(int)group;
- (UIPreferencesTableCell *)preferencesTable:(UIPreferencesTable *)aTable
    cellForRow:(int)row inGroup:(int)group;

- (void) setTextView:(MyTextView*)tv;
- (void) resize;

- (void) setEncoding:(NSString*)enc;
- (void) setFont:(NSString*)font;
- (void) setFontSize:(NSString*)fontSize;

@end

