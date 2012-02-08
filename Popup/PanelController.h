#import "BackgroundView.h"
#import "StatusItemView.h"
#import "HNWebView.h"
#import <WebKit/WebKit.h>
#import <AppKit/AppKit.h>

@class PanelController;

@protocol PanelControllerDelegate <NSObject, WebPolicyDecisionListener>

@optional

- (StatusItemView *)statusItemViewForPanelController:(PanelController *)controller;

@end

#pragma mark -

@interface PanelController : NSWindowController <NSWindowDelegate>
{
    BOOL _hasActivePanel;
    BackgroundView *_backgroundView;
    id<PanelControllerDelegate> _delegate;
    NSButton *_button;
    HNWebView *_webview;
}

@property (assign) IBOutlet BackgroundView *backgroundView;
@property (assign) IBOutlet NSButton *button;
@property (assign) IBOutlet HNWebView *webview;


@property (nonatomic, assign) BOOL hasActivePanel;
@property (nonatomic, readonly) id<PanelControllerDelegate> delegate;

- (id)initWithDelegate:(id<PanelControllerDelegate>)delegate;

- (void)openPanel;
- (void)closePanel;
- (NSRect)statusRectForWindow:(NSWindow *)window;
-(IBAction) refreshClicked: (id) sender;
-(id) refreshWebsite;
@end
