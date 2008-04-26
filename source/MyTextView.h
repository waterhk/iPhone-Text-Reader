//
//
//   textReader.app -  kludged up by Jim Beesley
//   This incorporates inspiration, code, and examples from (among others)
//   * http://iphonedevdoc.com/index.php - random hints
//   * jYopp - http://jyopp.com/iphone.php - UIOrientingApplication example
//   * mxweas - UITransitionView example
//   * thebends.org - textDrawing example
//   * "iPhone Open Application Development" by Jonathan Zdziarski - FileTable/UIDeletableCell example
//   * BooksApp, written by Zachary Brewster-Geisz (and others)
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
//



#import <UIKit/UIKit.h>
#import <UIKit/NSString-UIStringDrawing.h>
#import <CoreGraphics/CGGeometry.h>
#import <WebCore/WebFontCache.h>
#import <UIKit/UIAlertSheet.h>
#import <UIKit/UIViewTapInfo.h>
#import <UIKit/UIView-Geometry.h>
#import <UIKit/UISliderControl.h>


@class textReader;

// *****************************************************************************
@interface MyTextView : UIView {

	textReader   	 *trApp;
	NSLock	         *screenLock;

	NSMutableString  *text;
	int               start;
	int               end;

	NSString         *font;
	float             fontSize;
	int               color;
	bool              ignoreNewLine;

	NSString         *fileName;

	bool              pageUp;
}

- (void) setTextReader:(textReader*)tr;

- (id)   init;
- (id)   initWithFrame:(CGRect)rect;

- (void) fillBkgGroundRect:(CGContextRef)context rect:(CGRect)rect;
- (void) setColor:(int)newColor;
- (void) setIgnoreNewLine:(bool)ignore;
- (bool) getIgnoreNewLine;
- (int)  getColor;
- (void) pageUp;
- (void) pageDown;

- (bool)              openFile:(NSString *)name start:(int)startChar;
- (NSMutableString *) getText;
- (void)              setStart:(int)newStart;
- (int)               getStart;
- (int)               getEnd;
- (NSString*)         getFileName;

- (NSString *)getFont;
- (bool)setFont:(NSString*)newFont;
- (int)getFontSize;
- (bool)setFontSize:(int)newSize;

- (void) mouseDown:(struct __GSEvent*)event;
- (void) mouseUp:(struct __GSEvent *)event;

@end // MyTextView : UIView


